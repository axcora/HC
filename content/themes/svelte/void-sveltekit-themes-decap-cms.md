---
layout: themes-detil.cax
title: VOID — SvelteKit Theme for AI & SaaS Content-Driven Sites
description: A SvelteKit theme for AI and SaaS founders, developers, and small teams. Content collections in JSON and Markdown, SEO meta from frontmatter, built-in RSS and sitemap, and an optional Decap CMS edition for browser-based editing.
image: svelte/sveltekit-template_vaatjg.jpg
features:
 - SvelteKit 3 Framework
 - Svelte 5 Components
 - JSON + Markdown Content Collections
 - SEO Meta Built In
 - Open Graph + Twitter Card
 - Built-in RSS Feed and Sitemap
 - Accessible Base Components
 - File-Based Routing
 - Nested Layouts and Dynamic Routes
 - Decap CMS Ready (Code + CMS Edition)
 - Netlify Identity + Git Gateway
 - Modern Host Support: Netlify, Vercel, Cloudflare Pages
 - Production Build for cPanel, Plesk, DirectAdmin, VPS
 - Two Editions: Code Only and Code + Decap CMS
download: https://creativitaz.gumroad.com/l/svelte-void
demo: https://sveltekit-void.pages.dev/
tags:
  - themestemplate
  - website themes
  - website template
  - starter
  - svelte
  - sveltekit
  - sveltekit theme
  - sveltekit template
  - svelte theme
  - decap cms
  - sveltekit cms
  - jamstackthemes
  - premiumthemes
  - saas theme
  - ai startup theme
  - seo theme
  - featured
  - featuredpremium
---

## What VOID Is

VOID is a SvelteKit theme for content-driven sites. It is built for AI and SaaS founders, indie developers, and small teams who need a fast, SEO-ready marketing site without rebuilding layout, content, and meta plumbing from scratch.

Layout is separated from content. Pages read from JSON and Markdown files. SEO meta is generated from page data. Routes stay focused on layout, so editing copy does not mean editing components.

This is a codebase, not a page builder. You get a working structure and a small set of components. Change copy in data files, not in components.

## The Problem It Solves

Building a SvelteKit marketing site from scratch means setting up routing, layouts, SEO meta, content loading, and a way to edit copy. That is a few days of work before the first page looks right.

VOID gives you that structure already wired:

- Routing with nested layouts and dynamic routes
- Content collections in JSON and Markdown
- SEO meta from frontmatter, not copy-paste
- Built-in RSS feed and sitemap endpoints
- Optional Decap CMS for browser-based editing

If you are launching an AI product, a SaaS landing page, or a documentation site, the first week should go into your copy and your product, not into wiring up meta tags and a content loader.

## What You Get

Both editions share the same core codebase. Here is what ships in both:

- Full SvelteKit source code
- JSON + Markdown content collections
- SEO meta built in (title, description, canonical, Open Graph, Twitter card)
- Accessible base components with ARIA attributes and keyboard-friendly focus states
- File-based routing with nested layouts and dynamic routes
- Built-in RSS feed at `/rss.xml`
- Built-in sitemap at `/sitemap.xml`
- Adapter config for Cloudflare, Netlify, Vercel, and static hosts
- Documentation access at the VOID docs site

The Code + Decap CMS edition adds:

- Decap CMS config at `static/admin/config.yml`
- Netlify Identity for editor login
- Git Gateway for commits without GitHub accounts
- Media management from the CMS
- Browser-based content editing

## Who It Fits

- AI and SaaS founders who need a marketing site with SEO and content structure already wired
- Developers who want a SvelteKit starting point with content collections
- Content teams that want browser-based editing without touching code
- Small teams that need a readable codebase one or two people can maintain
- Agencies building client sites on SvelteKit

## Who It Does Not Fit

- Projects that need drag-and-drop layout editing. VOID is not a page builder.
- Projects that need a full backend with auth, payments, and dashboards out of the box.
- Teams looking for a no-code page builder. This is a codebase with an optional CMS layer.

## Two Editions

**Code Only — $69**

The SvelteKit theme source, JSON and Markdown content setup, and SEO meta wiring. Best if you or your developer will manage content in code.

https://creativitaz.gumroad.com/l/svelte-void

**Code + Decap CMS — $129**

Everything in Code Only, plus a Decap CMS setup so editors can update content from a browser without touching the repo.

https://creativitaz.gumroad.com/l/svelte-void-cms

## Documentation

The rest of this article covers setup and content editing for both editions.

### Local Installation

1. Download and install [Node.js](https://nodejs.org/en/download/) (version 22.17 or newer).
2. Download the source code from Gumroad.
3. Create a new folder on your desktop and name it after your project.
4. Extract the source code into that folder.
5. Open a terminal and move into the project folder:

   ```
   cd C:\Users\pcname\Desktop\yourproject
   ```

   Replace `pcname` with your PC name and `yourproject` with your project folder name.

6. Install dependencies and start the dev server:

   ```
   npm install && npm run dev
   ```

7. Open `http://localhost:5173` in your browser.
8. To stop the dev server, press `Ctrl+C`.

### Project Structure

Two folders matter most when editing content:

- `src/lib/data/` — JSON files for site settings, navigation, and footer
- `src/content/` — Markdown files for pages, blog, and services

Start with `src/lib/data/site.json` to change the site name and URL. The RSS feed and sitemap endpoints read the `url` field from this file, so changing it once updates both.

### Update Content Without a CMS

Open `src/content/` and edit the Markdown files directly. Each file has frontmatter for SEO and page data, followed by the page body.

For site-wide settings, open `src/lib/data/site.json` and update:

- `name` — site name
- `url` — production URL used in canonical, RSS, and sitemap
- `brand` — mark, text, accent, and home link
- `defaultOgImage` — default Open Graph image
- `twitter` — card type and site handle

For navigation and footer, edit `src/lib/data/navbar.json` and `src/lib/data/footer.json`.

### Update Content With Decap CMS

This section applies to the Code + Decap CMS edition.

The CMS config lives at `static/admin/config.yml`. Each collection maps to a folder or file in the project:

- `site` — `src/lib/data/site.json`, `navbar.json`, `footer.json`
- `pages` — `src/content/home/`, `about/`, `contact/`
- `blog` — `src/content/blog/`
- `services` — `src/content/services/`
- `legal` — `src/content/legal/`

#### Run the CMS locally

Decap CMS needs a local backend to edit content during development. That backend is `decap-server`, and it runs in a second terminal.

Terminal 1 — SvelteKit dev server:

```
npm run dev
```

Terminal 2 — Decap local backend:

```
npx decap-server
```

`decap-server` starts a proxy that Decap uses to write to your local files. It usually runs on port 8081.

Open the CMS at:

```
http://localhost:5173/admin/
```

The trailing slash matters. `/admin` without a slash may redirect, but `/admin/` is the canonical path.

If you see a blank page, check the browser console. The most common cause is that `decap-server` is not running in the second terminal.

#### Enable the CMS in production

For production editing, you need Netlify Identity and Git Gateway. This requires a Netlify account and a GitHub repository.

1. Push your project to GitHub.
2. Deploy to Netlify.
3. In Netlify, go to **Integrations** → **Identity** → **Enable Identity**.
4. Under **Services** → **Git Gateway** → **Enable Git Gateway**.
5. Invite editors via **Identity** → **Invite users**.
6. Open `/admin/` on your deployed site.
7. Log in with the invited account.

Editors change content in the browser. Git Gateway commits to the repository. The site rebuilds on deploy.

### Push to GitHub

1. Create an account on [GitHub](https://www.github.com/).
2. Create a new repository and name it after your project.
3. Copy the commands from your GitHub repository page.
4. In your project folder, run:

   ```
   git init && git add . && git commit -m "my first commit" && git remote add origin https://github.com/username/myrepo
   git push -u origin main
   ```

   Replace `username` with your GitHub username, `myrepo` with your repository name, and `main` with your repository's default branch (for example `main` or `master` — check your GitHub repository page).

### Make Your Website Online

You can deploy to [Netlify](https://netlify.com), Vercel, or Cloudflare Pages. All three support SvelteKit.

1. Create an account with your GitHub account on Vercel, Netlify, or Cloudflare.
2. Create a new project on Vercel or Netlify. For Cloudflare, create a new Cloudflare Pages project.
3. Connect your GitHub repository.
4. Select the SvelteKit framework preset.
5. Set the build command to `npm run build`.
6. Set the output directory based on the adapter:

   | Adapter | Output directory |
   | :--- | :--- |
   | `@sveltejs/adapter-cloudflare` | `.svelte-kit/cloudflare` |
   | `@sveltejs/adapter-netlify` | `build` + `.netlify/` |
   | `@sveltejs/adapter-vercel` | `.vercel/output` |
   | `@sveltejs/adapter-static` | `build` |

7. For Cloudflare Pages, set `NODE_VERSION=22.17.0` (or higher) in environment variables.
8. Click deploy.

Your SvelteKit site is live.

### Production Build for PHP Hosting

If you want to run on PHP hosting like cPanel, Plesk, DirectAdmin, or a VPS, you need to build the project in static mode.

1. Install the static adapter:

   ```
   npm i -D @sveltejs/adapter-static
   ```

2. In `vite.config.js`, replace the adapter with:

   ```js
   import adapter from '@sveltejs/adapter-static';
   // ...
   adapter: adapter({ fallback: '404.html' })
   ```

3. Build the project:

   ```
   npm run build
   ```

4. Upload the contents of the `build/` folder to your hosting's public directory (for example `public_html` on cPanel).

Static hosting works for the marketing pages, blog, and docs. The Decap CMS admin panel needs a Git backend, so it does not run on plain PHP hosting without an OAuth proxy.

For most projects, modern static hosting like Netlify, Vercel, or Cloudflare Pages is the simpler path.

### RSS and Sitemap

Both endpoints read from your content collections at build time:

- `/rss.xml` — lists the latest blog posts
- `/sitemap.xml` — lists static pages and blog posts

The base URL for both comes from `src/lib/data/site.json` → `url`. Change it once, and both follow.

### SEO Meta

Each page defines its SEO fields in the frontmatter: title, description, canonical, Open Graph type, and image. A shared SEO component reads those fields and renders the tags.

This means you edit meta in one place per page, not in a separate head component. The output is consistent across pages, and the canonical URL follows the `url` in `site.json`.

## Tech Stack

- SvelteKit — file-based routing, SSR-ready
- Svelte 5 — runes and fine-grained reactivity
- Vite — build tool and dev server
- mdsvex — Markdown preprocessing for Svelte
- Marked — Markdown parser for content loading
- js-yaml — YAML frontmatter parser
- Decap CMS (optional) — Git-based content management, browser admin panel
- Netlify Identity (optional) — editor login
- Git Gateway (optional) — commits without GitHub accounts

## Requirements

- Node.js 22.17 or newer
- npm 10 or newer
- Basic comfort with SvelteKit, JSON, and Markdown
- For the CMS edition: a GitHub account and a Netlify account (free tier works)

## License

Single-purchase, unlimited-project license. Use in unlimited personal and client projects. No resale or redistribution of the theme.

## Links

- Demo: https://sveltekit-void.pages.dev/
- Documentation: https://sveltekit-void.pages.dev/docs/welcome
- Code Only — $69: https://creativitaz.gumroad.com/l/svelte-void
- Code + Decap CMS — $129: https://creativitaz.gumroad.com/l/svelte-void-cms
- Custom work: https://www.fiverr.com/creativitas/create-your-custom-website-and-app
- Support: creativebydre@gmail.com

## Thank You

Thank you for using VOID. We hope this starter saves you the setup time and lets you focus on your product and your copy.
