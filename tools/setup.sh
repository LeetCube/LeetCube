#!/bin/bash

main() {
    input
    case $lang in
    py)
        py
        ;;
    js)
        js
        ;;
    ts)
        js
        ;;
    go)
        golang
        ;;
    *)
        echo "We don't have setup in $lang yet"
        ;;
    esac
    echo "Completed setup"
}

input() {
    read -p "Enter py, js, ts, or go: " lang
    read -p "Enter [i] for install, or [u] for update: " setup
}

py() {
    if [ $setup = "i" ]; then
        conda install python
        conda install pandas
        conda install matplotlib
        conda install -c conda-forge tabulate
    elif [ $setup = "u" ]; then
        conda update conda
        conda update --all
    else
        echo Command invalid
    fi
}

js() {
    if [ $setup = "i" ]; then
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
        if [ $lang = "ts" ]; then
            npm install -D typescript
            npm install -D ts-node
            npm i --save-dev @types/node
            npm i --save-dev @types/chai
            npm i --save-dev @types/chai-as-promised
        fi
    elif [ $setup = "u" ]; then
        npm install -g npm@latest
        sudo npm install -g n # when prompted: enter your password
        n lts
        npm update
        echo node version $(node --version)
        echo npm version $(npm --version)
    else
        echo Command invalid
    fi
}

golang() {
    read -p "Enter the go dir to update: " dir
    if [ $setup = "u" ]; then
        cd $dir
        go get -u all
    fi
}

main
