import { IPlayer } from './IPlayer';
import { IScenario } from './IScenario';
import { IActiveCard } from './ICard';

export interface IGame {
    turnsLeft: number;
    players: IPlayer[];
    scenario: IScenario;
    activeCard: IActiveCard;
};