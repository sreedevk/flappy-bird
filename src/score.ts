import { type Application, Assets, Sprite, type Texture } from "pixi.js";
import { type State, Status } from "./game";

export class Score {
  public sprite: Sprite;
  private textures: Array<Texture>;

  update(_: Application, ctx: State) {
    if (ctx.status !== Status.PreGame) {
      this.sprite.visible = true;
      this.sprite.texture = this.textures[ctx.score];
    }
  }

  async load(app: Application) {
    const textureproms = Array.from(
      { length: 10 },
      (_, i) => `/assets/sprites/${i}.png`,
    ).map((tpath: string) => Assets.load(tpath));

    this.textures = await Promise.all(textureproms);
    this.sprite.texture = this.textures[1];

    this.sprite.anchor.set(0.5);
    this.sprite.position.set(app.screen.width / 2, 50);
    this.sprite.zIndex = 10;
  }

  constructor() {
    this.textures = [];
    this.sprite = new Sprite();
    this.sprite.visible = false;
  }
}
