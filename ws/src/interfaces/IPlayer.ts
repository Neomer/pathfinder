import { ICard, IActiveCard } from './ICard';

export interface IPlayer {
    username: string;
    role: IActiveCard;
    location: ICard;
};