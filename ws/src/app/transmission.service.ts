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

  private game: Subject<IGame> = new Subject<IGame>();

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
      if (msg.eventId === 0) {
        this.game.next(msg.data);
      }
    }, err => console.log(err), () => console.log('comlete'));
  }

  private const packagesProccessors = [
    // 0
  ];

  private sendData(reqId: number, data) {
    const pkg = {
      requestId: reqId,
      data
    };
    this.webSocketsProvider.next(pkg);
  }


  getGameInstance(): Subject<IGame> {
    return this.game;
  }
}

