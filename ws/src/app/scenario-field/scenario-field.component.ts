import { Component, OnInit } from '@angular/core';
import { TransmissionService } from '../transmission.service';
import { IGame } from '../../interfaces/IGame';

@Component({
  selector: 'app-scenario-field',
  templateUrl: './scenario-field.component.html',
  styleUrls: ['./scenario-field.component.less']
})
export class ScenarioFieldComponent implements OnInit {

  private game: IGame = null;

  constructor(private ts: TransmissionService) { 
    
  }

  ngOnInit() {
    //this.game = this.transmissionService.getGameInstance();
  }

}
