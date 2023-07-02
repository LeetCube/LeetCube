# Set up

## Python

- conda
- pandas
- tabulate

### install

#### conda

[Anaconda official](https://www.anaconda.com/)

#### Python

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

#### Matplotlib

[Matplotlib official](https://matplotlib.org/stable/users/installing/index.html)

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

## JavaScript

- node
- npm
- lodash

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

#### Prettier

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
