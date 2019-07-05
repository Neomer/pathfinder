import { Component, OnInit } from '@angular/core';
import { CommunicationServiceService } from '../communication-service.service';

@Component({
  selector: 'app-location',
  templateUrl: './location.component.html',
  styleUrls: ['./location.component.less']
})
export class LocationComponent implements OnInit {

  constructor(private service :CommunicationServiceService) { 
    
  }

  ngOnInit() {
  }

}
