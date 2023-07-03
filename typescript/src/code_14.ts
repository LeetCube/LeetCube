function longestCommonPrefix(strs: string[]): string {
    let prefix: string = "";

    for (let i = 1; i <= strs[0].length; i++) {
        for (let str of strs) {
            if (!str.startsWith(strs[0].substring(0, i))) {
                return prefix;
            }
        }

        prefix = strs[0].substring(0, i);
    }

    return prefix;
};
