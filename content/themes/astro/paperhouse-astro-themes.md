---
layout: themes-detil.cax
title: PaperHouse - Astro Bento Portfolio Template - Works, Blog, Docs, Order
description: PaperHouse is a premium Astro 7 + Tailwind 4 bento portfolio template with works, blog, docs, and order page. Markdown-driven, SEO-ready, one-time $45.
image: astro/astro-themes-paperhouse1_bdapzv.jpg
features:
  - Astro 7 + Tailwind 4
  - Bento Grid Portfolio
  - Works + Gallery + Categories
  - Blog + Tags + Prev/Next
  - Docs Site Built In
  - Contact Form + Meta Grid
  - SEO Per Page + OG + Twitter
  - Markdown + JSON Driven
  - Zero Hardcode
  - Own 100% Source
download: https://creativitaz.gumroad.com/l/paperhouse-astro-bento
demo: https://paperhouse-astro.pages.dev/
tags:
    - astro
    - astro template
    - bento portfolio
    - portfolio template
    - blog template
    - docs template
    - astro theme
    - paperhouse template
    - tailwind template
    - premiumthemes
---

## PaperHouse — Astro Bento Portfolio Template

If you have been looking for an Astro portfolio template that does not look like every other brutalist grid on the market, PaperHouse is worth a look. It is built with Astro 7 and Tailwind CSS 4, and it ships with a complete content system — works, blog, docs, and an order page. Everything is editable from markdown and JSON. No database, no admin panel, no monthly fees.

https://www.youtube.com/watch?v=YwnAax4okAg

### Why Astro 7 for Portfolios

Astro ships zero JavaScript by default. That single decision changes everything — page speed, Core Web Vitals, and how search engines rank your portfolio. Every page in PaperHouse is served as static HTML, which means it loads instantly on any device and any connection.

If you are comparing Astro against other static site frameworks, [Astro's official docs](https://astro.build) cover the technical details. For a portfolio that needs to convert visitors into clients, the numbers speak for themselves.

### What Is Inside PaperHouse

PaperHouse is not a one-page template. It ships with a complete structure that a working studio actually needs:

- **Home** — hero, marquee, bento works grid, feature block, journal preview, and a closing CTA
- **Works** — case studies with cover images, per-work galleries, three card sizes, and prev/next navigation
- **Journal** — blog posts with categories, tags, reading time, and prev/next
- **Docs** — a full documentation site built with its own collection and sidebar
- **Contact** — form with configurable fields, email, and a meta grid
- **Order** — a page built to close the sale

Each of these is a separate content collection. Adding a new work or blog post takes one markdown file.

### Built for Conversion

Most templates look good but do not convert. PaperHouse is engineered the other way around. Every page has a clear next step:

- Home has a hero CTA and a closing CTA
- Works cards link to case studies with a clear "next project" path
- Journal posts link to categories, tags, and other posts
- Contact page has a form and a meta grid showing license and response time
- Order page exists to close

This is the structure that sells on Gumroad and ThemeForest.

### Markdown and JSON — Zero Hardcode

Every piece of content in PaperHouse is editable without touching a layout file:

- **`src/content/works/`** — case studies as markdown
- **`src/content/blog/`** — journal posts as markdown
- **`src/content/pages/`** — static pages as markdown
- **`src/content/docs/`** — documentation as markdown
- **`src/content/contact/`** — contact page data
- **`src/data/*.json`** — brand, nav, footer, SEO, home copy, labels

You do not need to know Astro to run PaperHouse. If you can edit a markdown file, you can run the site.

### SEO Per Page

Every page in PaperHouse has its own title, description, and social share image. These are defined in `src/data/site.json` for static pages, and pulled from frontmatter for dynamic pages like works and blog posts.

The template also handles:

- Open Graph tags
- Twitter Cards
- Canonical URLs
- Clean URL structure
- Semantic HTML
- Sitemap-ready

This is what makes a portfolio rank on Google for the right keywords — designer portfolio, studio website, and similar.

### What You Get

- Full source code — no obfuscation, no hidden dependencies
- Astro 7 + Tailwind CSS 4
- 6 example works and 5 example blog posts
- Works, journal, and pages collections
- Bento grid with three card sizes
- Mobile-first responsive layout
- Custom 404 page
- Sitemap-ready
- Lifetime updates

### Who It Is For

- Designers tired of template sameness
- Freelancers who want to look bigger than they are
- Studios shipping portfolios for clients
- Developers who want a clean Astro starting point

If you have been comparing Astro themes or looking for a portfolio template that feels less like a theme and more like a system, PaperHouse is a good fit.

### License and Support

One-time $45. Unlimited personal and client projects. Not for resale as a template.

Every purchase includes lifetime updates and email support. Response within 24 hours, usually much faster.

### Download PaperHouse

[Get PaperHouse — $45 on Gumroad](https://creativitaz.gumroad.com/l/paperhouse-astro-bento)

[Live demo](https://paperhouse-astro.pages.dev/)


## Documentation

This documentation covers everything you need to install, configure, and ship PaperHouse. It is written for buyers who may not have used Astro before. Every section is practical and to the point.

### Requirements

Before you start, make sure you have:

- Node.js 18 or newer — download from nodejs.org
- A code editor — VS Code is recommended
- A terminal — Terminal on macOS, PowerShell on Windows

To check your Node version:

    node --version

If you see v18.0.0 or higher, you are ready.

### Installation

Step 1 — Unzip the download

After purchase, unzip the folder anywhere on your computer. You will end up with a folder like paperhouse-theme/.

Step 2 — Open the folder in your terminal

    cd path/to/paperhouse-theme

Step 3 — Install dependencies

    npm install

This takes about 30 seconds the first time. You only run it once.

Step 4 — Start the development server

    npm run dev

Open http://localhost:4321 in your browser. Any file change reloads automatically.

Step 5 — Build for production

    npm run build

This creates a dist/ folder with your optimized site. Upload this to your host.

Step 6 — Preview the production build

    npm run preview

### All Commands

| Command | What it does |
| :--- | :--- |
| npm install | Install dependencies (once) |
| npm run dev | Start dev server at localhost:4321 |
| npm run build | Build production site into dist/ |
| npm run preview | Preview the production build locally |

### Project Structure

    paperhouse-theme/
    ├── public/
    ├── src/
    │   ├── components/
    │   ├── content/
    │   ├── data/
    │   ├── layouts/
    │   ├── pages/
    │   └── styles/
    ├── astro.config.mjs
    ├── package.json
    └── README.md

The public/ folder holds static files served exactly as-is: favicon, logo mark, OG images, robots.txt, and any PDFs or self-hosted fonts. Any file in public/ is accessible at the root URL. Never put page content or source code here.

The src/components/ folder holds reusable UI components. Home page sections live in components/home/. Navbar, footer, and mobile drawer live in components/partials/.

The src/content/ folder holds every piece of content as markdown, split into collections: works, blog, pages, contact, and docs.

The src/data/ folder holds all site configuration as JSON: brand, nav, footer, SEO, home copy, and per-page labels.

The src/layouts/ folder holds Base.astro, the root layout. It handles meta tags, navbar, footer, and the mobile menu.

The src/pages/ folder holds all routes. Astro uses file-based routing, so every file in pages/ becomes a URL.

The src/styles/ folder holds globals.css, which contains Google Fonts, Tailwind import, design tokens, and global element styles.

### Astro Configuration

Open astro.config.mjs at the project root. Set your production domain:

    export default defineConfig({
      site: 'https://your-domain.com',
      vite: {
        plugins: [tailwindcss()]
      }
    });

Astro uses this for canonical URLs and sitemap entries. If it is wrong, search engines see duplicate pages and rankings drop. Use the exact URL people will visit, with no trailing slash.

To enable sitemap generation, run:

    npx astro add sitemap

This updates astro.config.mjs automatically and generates a sitemap-index.xml on build.

### Site Data

All site-wide content lives in src/data/site.json. Open it and edit the sections below.

Brand:

    "brand": {
      "name": "Your Studio",
      "initial": "Y",
      "tagline": "studio ~",
      "homeHref": "/"
    }

SEO defaults:

    "seo": {
      "title": "Your Studio — Design Portfolio",
      "titleTemplate": "%s — Your Studio",
      "description": "Your studio description for search engines.",
      "keywords": ["design studio", "portfolio", "branding"],
      "author": "Your Studio",
      "ogImage": "/astro.svg",
      "twitterHandle": "@yourstudio"
    }

Navigation:

    "nav": [
      { "href": "/about", "label": "About" },
      { "href": "/works", "label": "Works" },
      { "href": "/blog", "label": "Journal" },
      { "href": "/contact", "label": "Contact" }
    ]

CTA:

    "cta": {
      "label": "Start a project",
      "href": "/contact",
      "shortLabel": "Contact"
    }

Footer:

    "footer": {
      "headline": "Let's build something that lasts.",
      "body": "Your studio description.",
      "email": "hello@yourstudio.com",
      "columns": [ ... ],
      "copyright": "©2026 Your Studio"
    }

### Home Page

The home page is built from src/data/home.json. Every headline, label, and link comes from this file.

The hero headline uses a fragment system. Each part of the headline can have a style. Available styles: "italic opacity-60", "hl" (stabilo highlight), and "hl-skew" (tilted stabilo highlight). This is how you get italic words and highlighted words without writing HTML.

The marquee section uses two styles: "serif" for italic serif text and "label" for small uppercase sans.

The why section has a number, kicker, headline, body, tags, a CTA, and an image. Tags support an accent flag that renders a lime background.

The journal section pulls the three latest posts automatically from src/content/blog/. Only the labels are controlled from home.json.

The CTA section has a decorator, kicker, headline, body, a primary button, a secondary button, and an email link.

### Static Pages

Every simple page lives in src/content/pages/ as a markdown file. The filename becomes the URL. For example, about.md becomes /about.

Basic structure:

    ---
    title: "Page title"
    subtitle: "Short subtitle under the title."
    kicker: "Optional section label"
    ---

    ## Body content in markdown

Optional frontmatter fields:

- sidebar: line1 and line2 for a sticky sidebar
- columns: array of { title, items } for a 3-column footer
- ctas: array of { href, label, primary } for buttons
- meta: array of { label, value } for a meta grid

Every static page also needs an entry in src/data/site.json under pages, with title, description, image, and type.

### Contact Page

The contact page has its own collection and layout. The file is src/content/contact/contact.md.

Key fields:

- formAction: a Formspree or compatible endpoint
- email: displayed under the button and in the meta grid
- submitLabel: the button text
- fields: array of { name, placeholder, type, required }
- meta: array of { label, value } for the grid on the right

To set up Formspree:

1. Sign up at formspree.io
2. Create a new form
3. Copy the endpoint URL
4. Replace formAction in the frontmatter

The form supports text, email, tel, and textarea inputs.

### Works

Each case study is a markdown file in src/content/works/. The filename becomes the URL slug.

Required fields: title, description, category, year, client, cover.

Optional fields: gallery (array of image URLs), featured (true or false), size (normal, wide, or large).

Size controls how the card renders on the works grid. Normal is one column, wide is two columns, and large is two columns with a taller aspect ratio.

The gallery renders automatically if the array has at least one image. One image fills full width, two images sit side by side, and three or more alternate between full width and half width.

### Blog

Each journal post is a markdown file in src/content/blog/. The filename becomes the URL slug.

Required fields: title, description, date, category, cover, excerpt, tags.

Date format is YYYY-MM-DD. Posts are sorted by date in descending order, newest first. This affects the blog listing, the home page journal preview, and the prev/next navigation.

Reading time is calculated automatically from the body at 220 words per minute.

Tags are shared across posts. Two posts with the same tag appear on the same tag page.

### Docs

Documentation pages live in src/content/docs/ and are organized by src/data/docs.json. Each doc file has title, description, section, and order in its frontmatter.

To add a new doc page, create a markdown file and add it to a section in docs.json. The sidebar and prev/next navigation update automatically.

### Design Tokens

All design tokens live in src/styles/globals.css inside the @theme block. Change these to rebrand the entire site:

    @theme {
      --color-paper: #FFFCF7;
      --color-ink: #14120F;
      --color-stone: #EDE8DF;
      --color-lime: #E8FF5A;

      --font-serif: "Instrument Serif", serif;
      --font-sans: "Instrument Sans", "Syne", sans-serif;
      --font-hand: "Caveat", cursive;

      --radius-bento: 28px;
    }

Tailwind picks these up automatically. No config file needed.

### Deploy

Push your project to GitHub, then deploy to any static host.

Cloudflare Pages:

- Build command: npm run build
- Output directory: dist

Netlify:

- Build command: npm run build
- Publish directory: dist

Vercel:

- Framework preset: Astro
- Build command: npm run build
- Output directory: dist

GitHub Pages requires setting base in astro.config.mjs and adding a GitHub Actions workflow.

Once connected, every push to the main branch rebuilds and redeploys automatically.

### Headless CMS

PaperHouse works with any Git-based headless CMS. Add a browser dashboard on top of the markdown files without a database or server.

Options that work with PaperHouse:

- Sveltia CMS — modern, lightweight, free
- Decap CMS — industry standard, free
- Tina Cloud — visual editing with live preview
- Custom Git Dashboard — database-less, built around your business logic

All options connect to your GitHub repo. When you publish in the CMS, it commits the change and your host rebuilds automatically.

### SEO

Every page in PaperHouse has its own title, description, and social share image. These are defined in src/data/site.json for static pages, and pulled from frontmatter for dynamic pages like works and blog posts.

The layout handles Open Graph tags, Twitter Cards, canonical URLs, and semantic HTML. URLs are clean — no query strings, no file extensions.

To rank well, write unique descriptions for every work, post, and page. Keep them under 160 characters and include the main keyword.

### Customization Tips

- Change colors by editing the @theme block in globals.css
- Change fonts by editing --font-serif, --font-sans, and --font-hand
- Add a nav link by adding an entry to nav in site.json
- Add a footer column by adding an entry to footer.columns in site.json
- Add a page by creating a markdown file in content/pages/ and an entry in site.json
- Add a work by creating a markdown file in content/works/
- Add a blog post by creating a markdown file in content/blog/

### Support

If you get stuck, email axcora@gmail.com

For custom work — headless CMS integration, booking systems, or a fully bespoke Astro site — see the Fiverr profile linked in the product page.

### License

One-time $45. Unlimited personal and client projects. Not for resale as a template, theme, or starter kit.

Full license terms are included in the download.

### Download PaperHouse

Get PaperHouse — $45 on Gumroad: [https://creativitaz.gumroad.com/l/paperhouse-astro-bento](https://creativitaz.gumroad.com/l/paperhouse-astro-bento)

Live demo: [https://paperhouse-astro.pages.dev/](https://paperhouse-astro.pages.dev/)