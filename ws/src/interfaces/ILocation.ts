import { ICard } from './ICard';
import { IDeck } from './IDeck';

export interface ILocation {
    metadata: ICard;
    deck: IDeck;
    closed: boolean;
};