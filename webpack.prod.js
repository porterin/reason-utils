var path = require("path");
var HtmlWebpackPlugin = require("html-webpack-plugin");
const BundleAnalyzerPlugin = require('webpack-bundle-analyzer').BundleAnalyzerPlugin;

module.exports = (env) => {
  return {
    mode: "production",
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
      path: path.resolve("./"),
      filename: "bundle.js",
    },
    plugins: [
      new HtmlWebpackPlugin({
        filename: "index.html",
        template: "index.html",
      }),
      new BundleAnalyzerPlugin()
    ],
  };
};
