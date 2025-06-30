import { type Application, Assets, Sprite, type Texture } from "pixi.js";

export class Background {
  public sprite: Sprite;

  async load(app: Application) {
    const texture: Texture = await Assets.load(
      "/assets/sprites/background-day.png",
    );
    this.sprite = new Sprite(texture);
    this.sprite.anchor.set(0.5);
    this.sprite.position.set(app.screen.width / 2, app.screen.height / 2);
    this.sprite.zIndex = -90;
  }

  constructor(_app: Application) {
    this.sprite = new Sprite();
  }
}
