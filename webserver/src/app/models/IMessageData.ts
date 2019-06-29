import { ICard } from './Card';

export interface IMessageData{
    eventId: number,
    user: string,
    userPerson: string,
    data: string
}

export interface IScenarioMessageData extends IMessageData
{
    locations : ICard[]
}

export interface IUserMessageData extends IMessageData
{
    location : string;
}