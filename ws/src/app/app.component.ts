import { Component, OnInit } from '@angular/core';
import { IGame } from '../interfaces/IGame';
import { TransmissionService } from './transmission.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.less']
})
export class AppComponent implements OnInit {

  private game: IGame = null;

  constructor(private transmissionService: TransmissionService) { 
    this.transmissionService.getGameInstance().subscribe((game: IGame) => this.game = game, null, null);
  }

  ngOnInit() { }
}
