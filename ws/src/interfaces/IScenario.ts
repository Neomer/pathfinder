import { ICard } from './ICard';

export interface IScenario extends ICard {
    locations: ICard[];
};