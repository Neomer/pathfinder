import { Component, OnInit } from '@angular/core';
import { IGame } from '../../interfaces/IGame';
import { IScenario } from '../../interfaces/IScenario';

@Component({
  selector: 'app-scenario-field',
  templateUrl: './scenario-field.component.html',
  styleUrls: ['./scenario-field.component.less']
})
export class ScenarioFieldComponent implements OnInit {

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

  constructor() { }

  ngOnInit() {
  }

}
