import { Injectable } from '@angular/core';
import { IGame } from '../interfaces/IGame';
import { Observable, Observer, Subject } from 'rxjs';
import { webSocket, WebSocketSubject } from 'rxjs/webSocket';

@Injectable({
  providedIn: 'root'
})
export class TransmissionService {

  private webSocketsProvider: WebSocketSubject<any>;
  private observable;

  private observer;
  private game: IGame;

  private gameSubject: Subject<IGame> = new Subject<IGame>();

  constructor() {
    const openEvents = new Subject<Event>();
    this.webSocketsProvider = webSocket({
      url: 'ws://localhost:11555',
      openObserver: openEvents
    });
    openEvents.subscribe(msg => {
      console.log('open');
      this.sendData(0, null);
    }, err => console.log(err), () => console.log('comlete'));

    this.webSocketsProvider.subscribe( msg => {
      console.log(msg);
      switch (msg.eventId) {
        case 0: {
          this.game = msg.data;
          break;
        }
      } 
      this.gameSubject.next(this.game);
    }, err => console.log(err), () => console.log('comlete'));
  }

  private sendData(reqId: number, data) {
    const pkg = {
      requestId: reqId,
      data
    };
    this.webSocketsProvider.next(pkg);
  }

  getGameInstance(): Subject<IGame> {
    return this.gameSubject;
  }
}

