export interface Batch{
    id:string;
    name: string;
    description:string;
    created_at: string;
    result:string;
}

export interface BatchData{
    count?;
    next?;
    previous?;
    results:Batch[];

}