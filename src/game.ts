export enum Status {
  PreGame,
  InGame,
  GameOver
}

export type State = {
  status: Status,
  score: number
}
