import { Application, Assets, Sprite } from "pixi.js";
import { State, Status } from "./game";

export class GameOver {
  public sprite: Sprite

  update(_: Application, ctx: State) {
    if (ctx.status == Status.GameOver) {
      this.sprite.visible = true
    }
  }

  async load(app: Application) {
    this.sprite.visible = false
    this.sprite.texture = await Assets.load("/assets/sprites/gameover.png")
    this.sprite.anchor.set(0.5)
    this.sprite.x = app.screen.width / 2
    this.sprite.y = app.screen.height / 2
  }

  constructor(_: Application) {
    this.sprite = new Sprite()
  }
}
