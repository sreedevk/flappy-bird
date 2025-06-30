import { Application, Sprite, Assets, Texture, FederatedPointerEvent } from "pixi.js"
import { State, Status } from "./game"

const maxheight: number = 512
const mapytoangle = (yv: number) =>
  ((yv / maxheight) * 180 - 90) * (Math.PI / 180)

enum Flap {
  UpFlap = 0,
  DownFlap = 1,
  MidFlap = 2
}

export class Bird {
  public axis: number
  public flap: Flap
  public sprite: Sprite
  public speed: number

  private textures: Array<Texture>
  private direction: number

  private tempUpperBound: number

  private idleUpperBound: number
  private idleLowerBound: number

  private inGameLowerBound: number

  async load(app: Application, base: Sprite) {
    const texturepaths =
      [
        "/assets/sprites/yellowbird-upflap.png",
        "/assets/sprites/yellowbird-midflap.png",
        "/assets/sprites/yellowbird-downflap.png",
      ]

    const texturepromises = texturepaths.map(tpath => Assets.load(tpath))

    this.textures = await Promise.all(texturepromises)
    this.sprite.texture = this.textures[0]

    const x = app.screen.width / 2
    const y = app.screen.height / 2

    this.sprite?.anchor?.set(0.5)
    this.sprite?.position?.set(x, y)
    this.sprite.zIndex = 10
    this.inGameLowerBound = app.screen.height - base.height - (this.sprite.height / 2) - 3
  }

  updateGameOver(app: Application, ctx: State) {
    return
  }

  updatePreGame(app: Application, ctx: State) {
    const newY = this.sprite.y + this.direction
    if (newY <= this.idleUpperBound) {
      this.sprite.texture = this.textures[0]
      this.direction = 1 * this.speed
    } else if (newY >= this.idleLowerBound) {
      this.sprite.texture = this.textures[2]
      this.direction = -1 * this.speed
    }

    this.sprite.rotation = mapytoangle(this.sprite.y)
    this.sprite.y = this.sprite.y + this.direction
  }

  handlePointerDown(ctx: State) {
    if (ctx.status != Status.GameOver) {
      ctx.status = Status.InGame
      this.tempUpperBound = this.sprite.y - 60
      this.direction = -1 * this.speed
    }
  }

  updateInGame(app: Application, ctx: State) {
    if (this.tempUpperBound >= this.sprite.y) {
      this.sprite.texture = this.textures[0]
      this.direction = 1 * this.speed
      this.tempUpperBound = 0
    }

    if (this.direction > 0) {
      this.sprite.texture = this.textures[0]
    } else {
      this.sprite.texture = this.textures[1]
    }

    this.sprite.rotation = mapytoangle(this.sprite.y)
    this.sprite.y = this.sprite.y + this.direction

    if (this.sprite.y >= this.inGameLowerBound) {
      ctx.status = Status.GameOver
    }
  }

  update(app: Application, ctx: State) {
    switch (ctx.status) {
      case Status.GameOver:
        this.updateGameOver(app, ctx)
        break;
      case Status.PreGame:
        this.updatePreGame(app, ctx)
        break;
      case Status.InGame:
        this.updateInGame(app, ctx)
        break;
    }
  }

  constructor(app: Application) {
    this.axis = 0
    this.flap = Flap.MidFlap
    this.sprite = new Sprite()
    this.direction = 2.5
    this.speed = 3.5
    this.idleUpperBound = (app.screen.height / 5) * 1.75
    this.idleLowerBound = (app.screen.height / 5) * 2.90
    this.textures = []
    this.tempUpperBound = 0
    this.inGameLowerBound = 0
  }
}
