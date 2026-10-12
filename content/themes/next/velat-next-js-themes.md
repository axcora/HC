---
layout: themes-detil.cax
title: Next JS Documentation Theme Template — Velat
description: Free download and open source code Next Js documentation themes template markdown.
image: next/nextjs-themes-velat2_cusbmp.jpg
features:
 - React Framework
 - Js Lang
 - JSON Data
 - Markdown Doc
 - Next JS
download: https://creativitaz.gumroad.com/l/velat-next-js-ai-landing-page-themes-template
demo: https://velat-nextjs-themes.vercel.app/
tags:
  - nextjs
  - nextjsthemes
  - nextjstemplate
  - nextjs16
  - react
  - reactthemes
  - tailwindcss
  - typescript
  - jamstack
  - jamstackthemes
  - themestemplate
  - websitethemes
  - websitetemplate
  - documentationthemes
  - documentationtemplate
  - approuter
  - turbopack
  - ssg
  - staticgeneration
  - nextthemes
  - premiumthemes
  - featured
  - featuredthemes
---

## Velat — Next.js 16 Theme for AI Startups and Documentation Sites

Velat is a production-ready Next.js 16 theme built for AI startups, SaaS products, and documentation-heavy websites. It ships with 28 pre-rendered pages, full TypeScript source code, Tailwind CSS design system, and Markdown-powered content management.

The theme is designed for two audiences at once: founders who need a conversion-focused landing page, and developers who need a clean, extensible codebase. Both are served by the same foundation.

### What You Get

- Next.js 16 with App Router and Server Components
- Turbopack for fast builds (ready in 6 seconds)
- Full TypeScript — no `any`, no `@ts-ignore`
- Tailwind CSS with a custom design system
- Markdown-powered blog and product catalog
- Multi-page documentation with sidebar navigation
- Dark mode with system detection — no flash of wrong theme
- SEO metadata, Open Graph, sitemap, and robots.txt
- Zero-configuration deployment to Vercel

### Pages Included

- **Home** — hero, logo cloud, bento grid, proof metrics, pricing teaser
- **About** — manifesto, team grid, CTA
- **Products** — filterable catalog with search and pagination
- **Product detail** — features, pricing, related items
- **Blog** — filterable list with categories and pagination
- **Blog post** — table of contents, share button, related posts
- **Contact** — validated form with Formspree integration
- **Docs** — multi-page documentation with sidebar navigation

### Tech Stack

**Framework:** Next.js 16 (App Router)
**Language:** TypeScript 5
**Styling:** Tailwind CSS 3
**Bundler:** Turbopack
**Fonts:** next/font (Playfair Display + Inter)
**Content:** Markdown + JSON
**Forms:** react-hook-form + zod
**Icons:** lucide-react
**Animation:** CSS transitions

No unnecessary dependencies. Every package has a reason to be there.

### Content Management

All site content lives in the `data/` folder as JSON or Markdown. You never need to edit `.tsx` files to change text.

- `data/configuration.json` — site name, navbar, footer, home page, contact, SEO
- `data/about.json` — about page content
- `data/blog/index.json` + `*.md` — blog posts
- `data/products/index.json` + `*.md` — product catalog

Add a Markdown file → the page appears automatically. Delete it → the page disappears.

---

## Documentation

How to install and work with the Velat Next.js theme project.

### Requirements

Before installing, make sure you have:

- **Node.js 20.9 or later** — [download here](https://nodejs.org) (pick the LTS version)
- **npm** — comes bundled with Node.js, no separate install needed

Verify both are installed:

```bash
node --version
npm --version
```

Both commands should return version numbers (e.g., `v22.10.0`). If you see an error like `node is not recognized`, restart your computer and try again.

### Local Installation

Follow these steps to run Velat on your local machine.

**Step 1: Download and install Node.js**

Go to https://nodejs.org and download the LTS version. Run the installer and click Next through every screen. Restart your computer after installation.

**Step 2: Download the source code**

Download the project source code from Gumroad after purchase. You'll receive a ZIP file containing the full theme.

**Step 3: Create a project folder**

Create a new folder on your desktop and name it something meaningful, like `velat-project` or `my-ai-startup`.

**Step 4: Extract the source code**

Extract the ZIP file contents into your project folder. The folder should now contain `app/`, `components/`, `lib/`, `data/`, `public/`, `package.json`, and other files.

**Step 5: Open a terminal in the project folder**

**Windows:**

1. Open the project folder in File Explorer
2. Click the address bar at the top
3. Type `cmd`
4. Press Enter

**macOS / Linux:**

1. Right-click the project folder in Finder
2. Select **New Terminal at Folder**

**Step 6: Navigate via terminal (alternative)**

If you prefer to navigate manually, open a terminal and run:

```bash
cd C:\Users\pcname\Desktop\yourproject
```

Replace `pcname` with your Windows username, and `yourproject` with your project folder name.

**Step 7: Install dependencies**

In the terminal, run:

```bash
npm install
```

This downloads all required packages. It takes 1–3 minutes depending on your internet connection.

Warnings in yellow are normal. Only stop if you see a red **Error** message.

**Step 8: Start the development server**

Run:

```bash
npm run dev
```

Wait a few seconds. You'll see:

```
▲ Next.js 16.4.0 (Turbopack)
- Local: http://localhost:3000
✓ Ready in 6.6s
```

**Step 9: Open in browser**

Open your browser and go to:

```
http://localhost:3000
```

The Velat homepage should load.

**Step 10: Stop the server**

To stop the development server, press `Ctrl + C` in the terminal.

### Available Commands

| Command | Purpose |
|---|---|
| `npm run dev` | Start local development server on port 3000 |
| `npm run build` | Create an optimized production build |
| `npm run start` | Run the production build locally |
| `npm install` | Install dependencies |

**Typical workflow before deploying:**

```bash
npm run build
npm run start
```

This tests the production version on your machine before pushing it live.

### Customizing Content

All content is stored in `data/`. Change the text and the browser updates automatically.

**Site name, navbar, footer, home page copy:**

Open `data/configuration.json`. This file controls:

- Site name, title, description, favicon
- SEO settings (baseUrl, sitemap, Google verification)
- Navbar links and CTA button
- Footer columns and copyright
- Home page copy (hero, bento section, proof metrics, pricing)
- Contact page (email, form config)

**Blog posts:**

Each post is a single `.md` file inside `data/blog/`:

```markdown
---
title: "Your Post Title"
slug: "your-post-slug"
date: "2026-10-12"
author: "Your Name"
category: "Engineering"
description: "A short summary."
readingTime: "5 min"
image: "/images/your-image.webp"
---

Your content goes here in Markdown.
```

**Products:**

Same structure, inside `data/products/`:

```markdown
---
title: "Product Name"
slug: "product-name"
price: "$49/Mo"
category: "Automation"
description: "Full description."
shortDesc: "Short summary."
features:
  - "Feature one"
  - "Feature two"
image: "/images/your-image.webp"
---

Detailed content here.
```

**Images:**

Drop your images into `public/images/`. Reference them as `/images/your-file.webp`.

**Colors and fonts:**

- Colors: edit `app/globals.css` (search for hex values like `#D9F99D`)
- Fonts: edit `app/layout.tsx` (Playfair Display + Inter imports)

### Deployment

Deploy Velat to production in under five minutes.

**Push to GitHub:**

```bash
git init
git add .
git commit -m "Initial commit"
git branch -M main
git remote add origin https://github.com/YOUR-USERNAME/YOUR-REPO.git
git push -u origin main
```

**Deploy with Vercel:**

1. Go to https://vercel.com
2. Sign up with GitHub
3. Click **Add New** → **Project**
4. Select your repository → **Import**
5. Leave all settings as default
6. Click **Deploy**

Wait 1–3 minutes. You'll receive a live URL like `your-project.vercel.app`.

**Custom domain:**

1. Vercel project → **Settings** → **Domains**
2. Add your domain
3. Follow the DNS instructions
4. SSL is issued automatically

**Other platforms:**

Velat also deploys to Netlify, Cloudflare Pages, and Railway. All support Next.js 16 with zero configuration.

### Troubleshooting

**`node is not recognized`**

Node.js is not installed, or the terminal was not restarted after installation. Reinstall from https://nodejs.org and restart your computer.

**`Port 3000 is already in use`**

Another app is using port 3000. Close other terminals, or change the port in `package.json`:

```json
"dev": "next dev -p 3001"
```

**Blank page after `npm run dev`**

Stop the server (`Ctrl + C`), delete the `.next` folder, then run `npm run dev` again.

**Yellow warnings during `npm install`**

These are normal for modern JavaScript projects. Only red **Error** messages require attention.

### Full Documentation

For detailed guides on configuration, content management, deployment options, and troubleshooting:

**https://velat-nextjs-themes.vercel.app/docs**

Topics covered:

- Introduction — what Velat is, who it's for
- Installation — detailed setup walkthrough
- Configuration — every field in `configuration.json`
- Content — blog posts, products, Markdown syntax
- Deployment — Vercel, Netlify, Cloudflare, Firebase, AWS, cPanel, VPS
- Troubleshooting — common problems and solutions

### Support

If you get stuck:

1. Check the troubleshooting section first
2. Read the full error message — Next.js errors point to the exact file and line
3. Search the error text on Google or Stack Overflow
4. Check the official Next.js docs at https://nextjs.org/docs

### License

This theme is sold as a one-time purchase with unlimited usage rights for client work.

**You may:**
- Use it for unlimited personal projects
- Use it for unlimited client projects (agencies and freelancers welcome)
- Modify the code however you need
- Build and sell websites using this theme as a foundation

**You may not:**
- Resell, redistribute, or sublicense the theme itself
- Share the source files with others who have not purchased it
- Republish it (modified or unmodified) as a theme, template, or starter kit

In short: use it to build as many sites as you want, but don't sell the theme itself.

### Demo

**Live demo:** https://velat-nextjs-themes.vercel.app/

Test every page. Check dark mode. Open the docs. See the code quality before you buy.

### Download

**Get the Velat Next.js 16 theme — $49** → https://creativitaz.gumroad.com/l/velat-next-js-ai-landing-page-themes-template

One-time payment. Unlimited client projects. Full source code included.

---

Built with Next.js 16, Tailwind CSS, and Turbopack.
