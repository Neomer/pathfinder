import { Component, OnInit } from '@angular/core';
import { CommunicationServiceService } from '../communication-service.service';
import { IMessageData } from '../models/IMessageData';
import { ICard } from '../models/Card';

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
      if (messageData.eventId !== 2)
      {
        return;
      }
      this.communicationservice.selectedCard = JSON.parse(messageData.data);
  }

  ngOnInit() {
  }

}
