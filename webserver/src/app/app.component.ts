import { Component } from '@angular/core';
import { CommunicationServiceService } from './communication-service.service';
import { Serializer } from '@angular/compiler';
import { IMessageData } from './models/IMessageData';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.less']
})
export class AppComponent {
  title = 'webserver';
  constructor(private service: CommunicationServiceService){
    this.service = service;
    this.service.messageListeners.push(this.onMessage);
  }

  public onMessage(messageData: IMessageData)
  {
      if (messageData.eventId !== 0)
      {
        return;
      } 
      console.log('appcomponent: ' + messageData.data);
  }
}
