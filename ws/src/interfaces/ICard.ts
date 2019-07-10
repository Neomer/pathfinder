export interface ICard {
    typeId: number;
    cardTypeId: number;
    cardTypeName: string;
    description: string;
    title: string;
    typeName: string;
}

export interface IActiveCard extends ICard {
    attributes: string[];
}