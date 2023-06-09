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
    *)
        echo We don\'t have set up in $lang yet
        ;;
    esac
}

input() {
    read -p "Enter py, or js: " lang
    read -p "Enter [i] for install, or [u] for update: " setup
    # read -p "Enter linux, or mac: " os
}

py() {
    if [ $setup = "i" ]; then
        conda install pandas
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
    elif [ $setup = "u" ]; then
        npm install -g npm@latest
        sudo npm install -g n # when prompted: enter your password
        n lts
        echo node version $(node --version)
        echo npm version $(npm --version)
    else
        echo Command invalid
    fi
}

main
