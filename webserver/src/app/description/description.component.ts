import { Component, OnInit } from '@angular/core';
import { CommunicationServiceService } from '../communication-service.service';
import { IMessageData } from '../models/IMessageData';

@Component({
  selector: 'app-description',
  templateUrl: './description.component.html',
  styleUrls: ['./description.component.less']
})
export class DescriptionComponent implements OnInit {

  constructor(private communicationservice: CommunicationServiceService) { 
    this.communicationservice.messageListeners.push(this.onMessage);
  }

  public onMessage(messageData: IMessageData)
  {
      if (messageData.eventId !== 1)
      {
        return;
      } 
      console.log('appcomponent: ' + messageData.data);
  }

  ngOnInit() {
  }

}
