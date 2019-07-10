import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ScenarioFieldComponent } from './scenario-field.component';

describe('ScenarioFieldComponent', () => {
  let component: ScenarioFieldComponent;
  let fixture: ComponentFixture<ScenarioFieldComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ScenarioFieldComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ScenarioFieldComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
