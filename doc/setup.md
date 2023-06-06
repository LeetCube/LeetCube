# Set up

## JavaScript

-   node
-   npm
-   lodash

### install

#### node, npm

Select 1 of the options:

1. [nodejs official](https://nodejs.org/en)
2. [nvm](https://github.com/nvm-sh/nvm#install--update-script)

> Reference:
> [Medium on node](https://medium.com/@iam_vinojan/how-to-install-node-js-and-npm-using-node-version-manager-nvm-143165b16ce1) > [StackOverflow on restart shell](https://unix.stackexchange.com/questions/217905/restart-bash-from-terminal-without-restarting-the-terminal-application-mac)

```shell
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.39.3/install.sh | bash
exec $SHELL
echo Terminal restarted
command -v nvm
echo You should see nvm
nvm install --lts
echo node version $(node --version)
echo npm version $(npm --version)
npm i --save-dev lodash
```

#### lodash

[lodash official](https://lodash.com/)

```shell
npm i --save-dev lodash
```

### update

```shell
npm install -g npm@latest
sudo npm install -g n # when prompted: enter your password
n lts
echo node version $(node --version)
echo npm version $(npm --version)
```
