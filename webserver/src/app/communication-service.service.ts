import { Injectable } from '@angular/core';
import { IMessageData } from './models/IMessageData';

@Injectable({
  providedIn: 'root'
})
export class CommunicationServiceService {

  private status : string = 'Не подключен';
  public user : string = 'Василий';
  public userPerson : string = 'Харск';
  public scene : number = 0;

  public messageListeners : Function[] = [];
  public ws = new WebSocket("ws://192.168.18.48:11555");
  private messageData: IMessageData;
  constructor() { 
    this.ws.onopen = (event) => {
    this.status = 'Подключен';
    this.sendMessage('{"hello": "kek"}');
    this.ws.onmessage = (event) => {
      console.log(event);
        this.messageData = JSON.parse(event.data);
        this.messageListeners.forEach(a=> a(this.messageData));
    };
    this.ws.onclose = (event) => {
      this.status = 'Не подключен';
      console.log(event);
    }
  };
  }

  public sendMessage(message : string){
    this.ws.send(message);
  }
}

