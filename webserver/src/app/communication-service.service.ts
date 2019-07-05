import { Injectable } from '@angular/core';
import { IMessageData, IUserMessageData } from './models/IMessageData';
import { ICard } from './models/Card';
import { IUser } from './models/User';

@Injectable({
  providedIn: 'root'
})
export class CommunicationServiceService {

  private status : string = 'Не подключен';
  public user : string = 'Василий';
  public userPerson : string = 'Харск';
  public scene : number = 0;
  public cards : ICard[] = [];
  public selectedCard : ICard;
  public users : IUser[] = [];

  public messageListeners : Function[] = [];
  private imageUrls: string = 'assets/images/';
  public ws = new WebSocket("ws://192.168.18.48:11555");
  constructor() { 
    this.ws.onopen = (event) => {
    this.status = 'Подключен';
    this.sendMessage('{"hello": "kek"}');
    this.ws.onmessage = (event) => {
      console.log(event);
      this.updateData(event);
        ;
    };
    this.ws.onclose = (event) => {
      this.status = 'Не подключен';
      console.log(event);
    }
  };
  }
  updateData(event: MessageEvent)
  {
    var messageData : IMessageData = JSON.parse(event.data);
    switch (messageData.eventId)
    {
      //addUser
      case 1: {
        debugger;
          var userData : IUserMessageData = JSON.parse(messageData.data);
          var usr : IUser = { name: userData.user, person: userData.userPerson, location: userData.location};
          var index = this.users.findIndex(a => a.name == userData.user);
            if (index >= 0){
              this.users[index] = usr;
            }
            else{
              this.users.push(usr);
            };
          this.users.push({name: userData.user, person: userData.userPerson, location: userData.location})
          break;
        }
      // description
      case 2: {
        this.scene = 2;
      }
      // TargetLocation
      case 3: {
        this.scene = 3;
      }

        default:{
          break;
        }
    }
    this.messageListeners.forEach(a=> a(messageData));
  }
  
  public getImage(card :ICard)
  {
    if (card === undefined)
    {
      return this.imageUrls + 'undefined.png';
    }
    return this.imageUrls + card.typeName + '/' + card.title + '.png';
  }

  public sendMessage(message : string){
    this.ws.send(message);
  }
}

