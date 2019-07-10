import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class LoggerService {

  constructor() {
    this.log("Logger created.");
  }

  log(text: string) {
    console.log(text);
  }
}
