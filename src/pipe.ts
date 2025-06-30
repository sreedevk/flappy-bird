export enum Orientation {
  Up,
  Down
}

export class Pipe {
  public height: number
  public orientation: Orientation

  constructor(orientation: Orientation) {
    this.height = Math.random()
    this.orientation = orientation
  }
}
