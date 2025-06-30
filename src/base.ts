import { type Application, Assets, Sprite, type Texture } from "pixi.js";
import { type State, Status } from "./game";

export class Base {
  public sprite: Sprite;
  public framecount: number;

  async load(app: Application) {
    const baseOriginX = app.screen.width / 2;
    const texture: Texture = await Assets.load("/assets/sprites/base.png");

    this.sprite.texture = texture;
    this.sprite.anchor.set(0.5);
    this.sprite.position.set(
      baseOriginX,
      app.screen.height - this.sprite.height / 2,
    );
    this.sprite.zIndex = 10;
  }

  update(app: Application, state: State) {
    const baseOriginX = app.screen.width / 2;

    this.framecount = (this.framecount - 1) % 24;
    if (state.status !== Status.GameOver) {
      this.sprite.position.x = baseOriginX + this.framecount;
    }
  }

  constructor() {
    this.sprite = new Sprite();
    this.framecount = 0;
  }
}
