import pandas as pd
from collections import defaultdict

df_contributors = pd.read_json("../data/contributors.json")
df_contributors = df_contributors.sort_values("first_commit")
md_contributors = df_contributors.to_markdown(index=False)
n, _ = df_contributors.shape

dict_langs = defaultdict(int)
for langs in df_contributors["langs"]:
    for lang in langs:
        dict_langs[lang] += 1

df_langs = pd.DataFrame.from_dict(dict_langs, orient="index", columns=["count"])
df_langs = df_langs.reset_index(names="langs")
df_langs = df_langs.sort_values(by="count", ascending=False)
ax = df_langs.plot.bar(
    x="langs", y="count", ylabel="contributors count", rot=0, legend=False
)
fig = ax.get_figure()
fig_name = "figs/langs.png"
fig.savefig(fig_name)

with open("contributors.md", "w") as file:
    file.write(f"# Contributors\n")
    file.write(f"We have {n} contributors.\n\n")
    file.write(f"![]({fig_name})\n\n")
    file.write(md_contributors)
