import { Component, OnInit, Input } from '@angular/core';
import { ICard } from 'src/interfaces/ICard';

@Component({
  selector: 'app-card',
  templateUrl: './card.component.html',
  styleUrls: ['./card.component.less']
})
export class CardComponent implements OnInit {

  @Input() model: ICard;

  constructor() {  }

  ngOnInit() {
    console.log(this.model);
  }

  getCardContainerStyle() {
    return {
      'background-image': "url('assets/images/" + this.model.typeName + ".png"
    }
  }
}
