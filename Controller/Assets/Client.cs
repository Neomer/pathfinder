using System;
using System.Net.Sockets;
using System.Text;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Client : MonoBehaviour
{
    #region Public Variables
    [Header("Network")] //10555 client //
    public string ipAddress = "192.168.18.48";
    public int port = 10555;
    [Header("UI References")]
    public Button sendCloseButton;
    public Text ClientLogger = null;
    #endregion

    #region Network m_Variables
    private TcpClient m_client;
    private NetworkStream m_netStream = null;
    private byte[] m_buffer = new byte[49152];
    private int m_bytesReceived = 0;
    private string m_receivedMessage = "";
    #endregion

    //Set UI interactable properties
    private void Start()
    {
        sendCloseButton.interactable = false;
    }

    //Start client and stablish connection with server
    public void StartClient()
    {
        //Early out
        if (m_client != null)
        {
            ClientLog("There is already a runing client", Color.red);
            return;
        }

        try
        {
            m_client = new TcpClient();
            m_client.Connect(ipAddress, port);

            ClientLog("Client Started2", Color.green);

            m_netStream = m_client.GetStream();
            m_netStream.BeginRead(m_buffer, 0, m_buffer.Length, MessageReceived, null);

            sendCloseButton.interactable = true;

            SceneManager.LoadScene("MainWindow");
        }
        catch (SocketException)
        {
            ClientLog("Socket Error: Start Server first", Color.red);
            CloseClient();
        }
    }

    private void Update()
    {
        if (!string.IsNullOrEmpty(m_receivedMessage))
        {
            ClientLog("Msg recived on Client: " + "<b>" + m_receivedMessage + "</b>", Color.green);
            m_receivedMessage = "";
            sendCloseButton.interactable = false;

            ClientLog("Close Connection with Server", Color.red);
        }
    }

    public void SendMessageToServer()
    {
        if (!m_client.Connected) return;
            
        sendCloseButton.interactable = false;

        m_netStream = m_client.GetStream();

        m_netStream.BeginRead(m_buffer, 0, m_buffer.Length, MessageReceived, null);

        string sendMsg = "{\"eventId\": 123, \"Id\": 2}";
        byte[] msg = Encoding.ASCII.GetBytes(sendMsg);
        m_netStream.Write(msg, 0, msg.Length);
        //ClientLog("Msg sended to Server: " + "<b>Close</b>", Color.blue);
    }

    private void MessageReceived(IAsyncResult result)
    {
        if (result.IsCompleted && m_client.Connected)
        {
            m_bytesReceived = m_netStream.EndRead(result);
            m_receivedMessage = Encoding.ASCII.GetString(m_buffer, 0, m_bytesReceived);
            ClientLog("Msg recived on Client: " + "<b>" + m_receivedMessage + "</b>", Color.green);
            if (m_receivedMessage == "Close")
            {
                CloseClient();
            }
        }
    }

    private void CloseClient()
    {
        if (m_client.Connected)
        {
            m_client.Close();
            m_client = null;
      
            sendCloseButton.interactable = false;
        }
    }

    #region ClientLog
    private void ClientLog(string msg, Color color)
    {
        ClientLogger.text += '\n' + "<color=#" + ColorUtility.ToHtmlStringRGBA(color) + ">- " + msg + "</color>";
        Debug.Log("Client: " + msg);
    }
    private void ClientLog(string msg)
    {
        ClientLogger.text += '\n' + "- " + msg;
        Debug.Log("Client: " + msg);
    }
    #endregion

}