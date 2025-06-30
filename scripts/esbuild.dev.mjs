import esbuildServe from "esbuild-serve";

esbuildServe(
  {
    logLevel: "info",
    entryPoints: ["src/main.ts"],
    loader: { '.ts': 'ts' },
    bundle: true,
    target: ["esnext"],
    sourcemap: true,
    outfile: "public/bundle.min.js",
  },
  { root: "./public", port: 8080 },
);
