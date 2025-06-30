import { Application, Container } from "pixi.js";
import { Background } from "./background";
import { Base } from "./base";
import { Bird } from "./bird";
import { type State, Status } from "./game";
import { GameOver } from "./gameover";
import { Overlay } from "./overlay";
import { Score } from "./score";

(async () => {
  const app = new Application();
  const ctx: State = {
    score: 0,
    status: Status.PreGame,
  };

  await app.init({
    background: "#1099bb",
    width: 288,
    height: 512,
    antialias: true,
  });

  app.ticker.minFPS = 60;
  app.ticker.maxFPS = 120;

  document.getElementById("pixi-container")?.appendChild(app.canvas);

  const baseLayercontainer = new Container();

  const background = new Background(app);
  const base = new Base();
  const bird = new Bird(app);
  const score = new Score();
  const overlay = new Overlay(app);
  const gameover = new GameOver(app);

  await background.load(app);
  await base.load(app);
  await bird.load(app, base.sprite);
  await score.load(app);
  await overlay.load(app);
  await gameover.load(app);

  baseLayercontainer.addChild(background.sprite);
  baseLayercontainer.addChild(base.sprite);
  baseLayercontainer.addChild(bird.sprite);
  baseLayercontainer.addChild(score.sprite);
  baseLayercontainer.addChild(overlay.sprite);
  baseLayercontainer.addChild(gameover.sprite);

  baseLayercontainer.eventMode = "static";

  app.stage.addChild(baseLayercontainer);

  baseLayercontainer.on("pointerdown", (_) => {
    bird.handlePointerDown(ctx);
  });

  app.ticker.add((_) => {
    base.update(app, ctx);
    bird.update(app, ctx);
    score.update(app, ctx);
    overlay.update(app, ctx);
    gameover.update(app, ctx);
  });
})();
