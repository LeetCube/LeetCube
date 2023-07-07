# Set up

## Python

-   conda
-   python
-   pandas
-   matplotlib
-   tabulate

### install

#### conda

[anaconda official](https://www.anaconda.com/)

#### python

Create a new environment `leetcube` with python installed

```shell
conda create -n leetcube python
```

Or if you have an environment already, then

```shell
conda activate {environment}
conda install python
```

#### pandas

[pandas official](https://pandas.pydata.org/docs/getting_started/install.html)

```shell
conda install pandas
```

#### matplotlib

[matplotlib official](https://matplotlib.org/stable/users/installing/index.html)

```shell
conda install matplotlib
```

#### tabulate

```shell
conda install -c conda-forge tabulate
```

### update

```shell
conda update conda
conda update --all
```

## JS

-   node
-   npm
-   lodash
-   prettier

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
npm i --save-dev prettier
```

#### lodash

[lodash official](https://lodash.com/)

```shell
npm i --save-dev lodash
```

#### prettier

[Prettier official](https://prettier.io/docs/en/install.html)

```shell
npm i --save-dev prettier
```

### update

```shell
npm install -g npm@latest
sudo npm install -g n # when prompted: enter your password
n lts
npm update
echo node version $(node --version)
echo npm version $(npm --version)
```

## TS

### install

-   typescript
-   ts-node
-   @types

```shell
npm install -D typescript
npm install -D ts-node
npm i --save-dev @types/node
npm i --save-dev @types/chai
npm i --save-dev @types/chai-as-promised
```

### update

Same as JS.

## Go

-   go

### install

#### go

[go offcial](https://go.dev/doc/install)

To confirm installation, check

```shell
go version
```

### update

```shell
cd {dir}
go get -u all
```
