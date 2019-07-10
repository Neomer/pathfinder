import { IPlayer } from './IPlayer';
import { IScenario } from './IScenario';

export interface IGame {
    turnsLeft: number;
    players: IPlayer[];
    scenario: IScenario;
};