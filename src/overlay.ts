import { type Application, Assets, Sprite } from "pixi.js";
import { type State, Status } from "./game";

export class Overlay {
  public sprite: Sprite;

  update(_: Application, ctx: State) {
    if (ctx.status === Status.PreGame) {
      this.sprite.visible = true;
    } else {
      this.sprite.visible = false;
    }
  }

  async load(app: Application) {
    this.sprite.anchor.set(0.5);
    this.sprite.position.set(app.screen.width / 2, app.screen.height / 2 - 10);
    this.sprite.texture = await Assets.load("/assets/sprites/message.png");
    this.sprite.visible = false;
  }

  constructor(_: Application) {
    this.sprite = new Sprite();
  }
}
