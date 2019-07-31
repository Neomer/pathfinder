import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { ScenarioFieldComponent } from './scenario-field/scenario-field.component';
import { CardComponent } from './card/card.component';
import { TransmissionService } from './transmission.service';
import { LoggerService } from './logger.service';
import { Observable } from 'rxjs';
import { LocationCardComponent } from './location-card/location-card.component';
import { ExplorationFieldComponent } from './exploration-field/exploration-field.component';

@NgModule({
  declarations: [
    AppComponent,
    ScenarioFieldComponent,
    CardComponent,
    LocationCardComponent,
    ExplorationFieldComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [ ],
  bootstrap: [AppComponent]
})
export class AppModule { }
