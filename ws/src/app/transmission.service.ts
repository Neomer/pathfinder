import { Injectable, OnInit } from '@angular/core';
import { IGame } from '../interfaces/IGame';

@Injectable({
  providedIn: 'root'
})
export class TransmissionService implements OnInit {

  private webSocketsProvider: WebSocket;

  private game: IGame = {
    turnsLeft: 50,
    scenario: {
      typeId: 800,
      cardTypeId: 10,
      cardTypeName: 'Scenario',
      description: 'Если способность монстра обязывает вас перезарядить одну или несколько крат, сделайте это, а затем возьмите такое же количество карт.',
      title: 'Рубиих!',
      typeName: 'Rubiih',
      locations: [{
        cardTypeId: 12,
        description: null,
        title: 'Лес',
        cardTypeName: 'Локация',
        typeId: 1000,
        typeName: 'Forest'
      }, {
        cardTypeId: 12,
        description: null,
        title: 'Набережная',
        cardTypeName: 'Локация',
        typeId: 1001,
        typeName: 'Quay'
      }, {
        cardTypeId: 12,
        description: null,
        title: 'Ферма',
        cardTypeName: 'Локация',
        typeId: 1002,
        typeName: 'Farm'
      }, {
        cardTypeId: 12,
        description: null,
        title: 'Деревянный мост',
        cardTypeName: 'Локация',
        typeId: 1003,
        typeName: 'WoodenBridge'
      }, {
        cardTypeId: 12,
        description: null,
        title: 'Академия',
        cardTypeName: 'Локация',
        typeId: 1004,
        typeName: 'Quay'
      }]
    },
    players: [{
      username: 'user1',
      location: {
        cardTypeId: 12,
        description: null,
        title: 'Лес',
        cardTypeName: 'Локация',
        typeId: 800,
        typeName: 'Forest'
      },
      role: null
    }, {
      username: 'user2',
      location: null,
      role: null
    }]
  };

  constructor() { 
    this.webSocketsProvider = new WebSocket('ws://localhost:11555');
    this.webSocketsProvider.onopen = event => {
      console.log('Connection ready!');
    }
    this.webSocketsProvider.onerror = event => {
      console.log('Connection failed!');
      console.log(event);
    }
    this.webSocketsProvider.onclose = event => {
      console.log('Connection closed!');
    }
    this.webSocketsProvider.onmessage = event => {
      console.log('Message: ' + event.data);
    }
  }

  ngOnInit() {
    console.log("hello!");
  }

  getGameInstance() : IGame {
    return this.game;
  }
  
}

