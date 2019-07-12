import { Component, OnInit, Input } from '@angular/core';
import { ILocation } from '../../interfaces/ILocation';
import { CardComponent } from '../card/card.component';

@Component({
  selector: 'app-location-card',
  templateUrl: './location-card.component.html',
  styleUrls: ['./location-card.component.less']
})
export class LocationCardComponent extends CardComponent implements OnInit  {

  @Input() locationCard: ILocation

  constructor() {
    super();
  }

  ngOnInit() {
    console.log(this.locationCard);
    
  }

}
