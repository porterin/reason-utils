var path = require("path");
var HtmlWebpackPlugin = require("html-webpack-plugin");

module.exports = (env) => {
  return {
    mode: "development",
    devServer: {
      port: 8000,
      open: true,
      historyApiFallback: true,
      disableHostCheck: true, // For running localhost in browserStack
      liveReload: true,
      watchContentBase: true,
    },
    target: "web",
    entry: "./examples/index.bs.js",
    resolve: {
      extensions: [".bs.js", ".js", ".scss"],
    },
    module: {
      rules: [
        {
          test: /\.s[ac]ss$/i,
          use: [
            // Creates `style` nodes from JS strings
            "style-loader",
            // Translates CSS into CommonJS
            "css-loader",
            // Compiles Sass to CSS
            "sass-loader",
          ],
        },
        {
          test: /\.(png|jp(e*)g|svg|webp)$/,
          use: [
            {
              loader: "url-loader",
              options: {
                limit: 8000,
              },
            },
          ],
        },
        {
          test: /favicon\.ico$/,
          loader: "url-loader",
          query: {
            limit: 1,
            name: "[name].[ext]",
          },
        },
      ],
    },
    output: {
      path: path.resolve("/"),
      filename: "bundle.js",
    },
    plugins: [
      new HtmlWebpackPlugin({
        filename: "index.html",
        template: "index.html",
      }),
    ],
  };
};
