GitHub Pages usage for this repository

This `docs/` directory contains the content used by the MkDocs site and is the source for GitHub Pages deployment.

Quick start (local preview):

1. Create a Python virtual environment and activate it.

```powershell
python -m venv .venv
.\.venv\Scripts\Activate.ps1
```

2. Install requirements and run the dev server:

```powershell
pip install -r requirements.txt
mkdocs serve
# open http://127.0.0.1:8000
```

Deployment (automatic):

- This repository includes a GitHub Actions workflow `.github/workflows/deploy_mkdocs.yml` which builds the site and deploys to the `gh-pages` branch when you push to `main`.
- After the workflow runs, enable GitHub Pages in repository settings and set the source to the `gh-pages` branch (or GitHub may handle this automatically).

Notes:

- Edit `mkdocs.yml` to update `site_url` with your GitHub Pages URL: `https://<your-github-username>.github.io/<your-repo>`.
- If you prefer to deploy to `docs/` directly (without MkDocs build), you can configure Pages to serve from the `docs/` folder on `main` — but the provided workflow uses `mkdocs build` and publishes the rendered `site/` to `gh-pages`.
- To use a custom domain, add a `CNAME` file into the `site/` directory before deployment (or configure in repository settings).

Last trigger request: 2026-06-19 — commit to trigger GitHub Actions workflow.
