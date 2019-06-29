import { Component, OnInit } from '@angular/core';
import { CommunicationServiceService } from '../communication-service.service';
import { ICard } from '../models/Card'; 
import { IMessageData } from '../models/IMessageData';
@Component({
  selector: 'app-card',
  templateUrl: './card.component.html',
  styleUrls: ['./card.component.less'],
})
export class CardComponent implements OnInit {

  private cards : ICard[] = [];
  private scenario : ICard;
  private locations : ICard[] = [];
  private imageUrls: string = 'assets/images/';

  constructor(private communicationservice: CommunicationServiceService ) {
    this.communicationservice = communicationservice;
    this.communicationservice.messageListeners.push(this.onMessage);
    var card : ICard =  
    { 
      description: 'Description',
      title: 'Академия',
      typeId: 1,
      attributes : [ 'asdasd', 'asdasd'],
      typeName: 'location',
      hide: true,
    }
    var card2 : ICard=  
    {
      description: 'Description2',
      title: 'РубиИх',
      attributes : [ 'asdasd', 'asdasd'],
      typeId: 2,
      typeName: 'scenario',
      hide: true
    }
    var card3 : ICard=  
    {
      description: 'Description3',
      title: 'Харск',
      attributes : [ 'asdasd', 'asdasd'],
      typeId: 3,
      typeName: 'person',
      hide: true
    }
    this.updateCards( [card,card2, card3]); 
  }

  ngOnInit() {
  }

  public onMessage(messageData: IMessageData)
  {
      // if (messageData.eventId !== 1)
      // {
      //   return;
      // } 
      debugger;
      console.log('cardcomponent: ' + messageData);
      var newCards: ICard[] = JSON.parse(messageData.data)
      
      this.communicationservice.user = messageData.user;
      this.communicationservice.userPerson = messageData.userPerson;
      this.updateCards(newCards);

  }
  private updateCards(newCards : ICard[])
  {
    newCards.forEach(element => {
      var index = this.cards.findIndex(a => a.typeId == element.typeId);
      if (index >= 0){
        this.cards[index] = element
      }
      else{
        this.cards.push(element);
      }
    });
    this.scenario = this.cards.find(a => a.typeName === 'scenario');
    this.locations = this.cards.filter(a => a.typeName === 'location');
    this.communicationservice.scene = 0;
  }

  getImage(card :ICard)
  {
    if (card === undefined)
    {
      return this.imageUrls + 'undefined.png';
    }
    return this.imageUrls + card.typeName + '/' + card.title + '.png';
  }

  getPesonImage()
  {
    var card = this.cards.find(a=> a.title == this.communicationservice.userPerson);
    return this.getImage(card);
  }

  showdescription(card : ICard)
  {
    card.hide = !card.hide;
  }

}
