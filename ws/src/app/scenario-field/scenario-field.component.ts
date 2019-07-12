import { Component, OnInit } from '@angular/core';
import { TransmissionService } from '../transmission.service';
import { IGame } from '../../interfaces/IGame';
import { Observable } from 'rxjs/Observable';
import { Observer } from 'rxjs';

@Component({
  selector: 'app-scenario-field',
  templateUrl: './scenario-field.component.html',
  styleUrls: ['./scenario-field.component.less']
})
export class ScenarioFieldComponent implements OnInit {

  private game: IGame = null;

  constructor(private transmissionService: TransmissionService) { 
    this.transmissionService.getGameInstance().subscribe((game: IGame) => this.game = game, null, null);
  }

  ngOnInit() { }

}
