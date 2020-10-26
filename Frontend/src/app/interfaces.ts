export interface Batch{
    id:string;
    name: string;
    description:string;
    created_at: string;
}

export interface BatchData{
    count?;
    next?;
    previous?;
    results:Batch[];

}