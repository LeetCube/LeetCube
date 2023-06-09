import pandas as pd
from contributors_data import *

df_contributors = pd.DataFrame(contributors, columns=columns)
df_contributors = df_contributors.sort_values("first_commit")
md_contributors = df_contributors.to_markdown(index=False)

n, _ = df_contributors.shape

df_langs = pd.DataFrame(dict_langs)
df_langs = df_langs.sort_values(by="count", ascending=False)
md_langs = df_langs.to_markdown(index=False)

with open("contributors.md", "w") as file:
    file.write(f"# Contributors\n")
    file.write(f"We have {n} contributors.\n")
    file.write(md_langs)
    file.write(f"\n\n")
    file.write(md_contributors)
