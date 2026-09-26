---
layout: themes-detil.cax
title: CAX C SSG Starter
description: CAX SSG processes Markdown with frontmatter, renders templates,and generates a complete static website in under 50 milliseconds.
image: others/cax-starter_wgodf1.jpg
features:
 - Axcora
 - Axcora Zetta Core
 - Starter Project
 - Fast Website
 - Auto SEO
 - Fast Build
 - JSON Data
 - Yaml Data
 - Markdown Content
 - Batch SSG
 - Bash SSG
 - All Static Hosting support Vercel, Cloudflare, Netlify , Github Pages and others.
 - All PHP Hosting support Cpanel, Plesk, Direct Admin , VPS and others.
download: https://creativitaz.gumroad.com/l//cax
demo: https://cax.axcora.com/starter/
tags:
  - themestemplate
  - website themes
  - website template
  - blog template
  - themes
  - template
  - freethemes
  - featuredthemes
  - featured
  - otherthemes
  - others
date: 2026-08-07
---

### Introduction

This project is a starter themes for CAX SSG Project. with modern and dark design system.

CAX SSG is a high-performance static site generator written in pure [C](https://www.c-language.org/). Built for speed and simplicity, it processes Markdown content with frontmatter, renders templates, and generates a complete static website ready for deployment on any hosting platform.

### Features

Core
+ Pure C99 - No Node.js, Ruby, Python. Single binary.
+ Zero Dependencies - GCC + Make only.
+ Blazing Fast - Build 100 pages in < 50ms, < 5MB RAM.
+ Markdown + Frontmatter - YAML frontmatter support.
+ Pagination Controllers - Any content/*.md with collection:  pagination: becomes a list page.
+ Dynamic Collections - Every folder in content/ is a collection.
+ Multi Layout Support - posts-list.cax, services-list.cax, portfolio-grid.cax - fully dynamic.
+ Advanced Template Engine  variables: for , if, include, or.
+ Pagination Object - pagination.items, pagination.prev_url, pagination.next_url, pagination.current_page, pagination.total_pages, pagination.total_items.
+ SEO & Production Ready
+ Tags & Taxonomies - Automatic /tags/{tag}/ pages.
+ Sitemap - Full sitemap.xml including pagination pages.
+ Feeds - feed.xml, rss.xml, feed.json (JSON Feed 1.1).
+ Robots - Auto robots.txt with sitemap reference.
+ Built-in Server - cax start serves site/ at http://localhost:8080.

### Get Start

Need to download 
+ GCC Compiler
+ Make (or MinGW32-make on Windows)
+ Download CAX Minimalis on Gumorad: https://creativitaz.gumroad.com/l/cax-minimalis
+ Download CAX Minimalis on Github: https://github.com/mesinkasir/cax-minimalis

### Installation

First installation open terminal and run this command
```
# Clone
git clone https://github.com/mesinkasir/cax.git
cd cax

# Windows
mingw32-make clean
mingw32-make

# Linux / macOS
make clean
make linux
```

Quick Start
```
cax build         # Build to site/
cax start         # Build + serve at http://localhost:8080
```

### Architecture

CAX Minimalis Architecture
```
C:.
├── content/
│   ├── index.md                 # -> /index.html
│   ├── about.md                 # -> /about/index.html
│   ├── posts.md                 # Controller for posts collection
│   ├── services.md              # Controller for services collection
│   ├── posts/                   # Collection: posts
│   │   ├── why-c.md
│   │   └── template-engine.md
│   ├── products/                # Collection: products
│   └── services/                # Collection: services
├── templates/
│   ├── layouts/
│   │   ├── default.cax
│   │   ├── home.cax
│   │   ├── posts-list.cax       # List layout for posts
│   │   ├── services-list.cax    # List layout for services
│   │   ├── steampunk.cax
│   │   └── tag.cax
│   └── partials/
│       ├── header.cax
│       ├── footer.cax
│       └── index/
├── _data/
│   ├── metadata.json            # site.title, site.url, etc
│   ├── nav.json
│   └── config.json
├── public/
│   ├── css/style.css
│   └── img/
├── src/                         # C source
├── include/cax.h
├── site/                        # Generated output
│   ├── index.html
│   ├── sitemap.xml
│   ├── robots.txt
│   ├── feed.xml
│   ├── rss.xml
│   ├── feed.json
│   ├── posts/
│   │   ├── index.html
│   │   └── page/2/index.html
│   └── tags/
├── Makefile
└── cax.exe
```

### Media

Cax is support media folder you can put css, js, image, video, pdf and others for your media static on `public`

### Configuration

First you need to setup your site open on `_data/config.yaml`.

SEO Setup
```
title: "Static Site Generator Built in Pure C"
description: "Blazing fast zero dependencies,and no runtime overhead."
image: "/img/c.webp"
logo: "/img/c.webp"
url: "/"
author: "AXCORA"
```

Navbar Setup
```
navbar_title: "CAX SSG BLOG"
navbar_list:
  - name: "Home"
    url: "/"
  - name: "Article"
    url: "/posts/"
  - name: "About"
    url: "/about/"
  - name: "Docs"
    url: "https://cax.axcora.com/about/"
  - name: "Download"
    url: "https://creativitaz.gumroad.com/l//cax"
  - name: "Github"
    url: "https://github.com/mesinkasir/cax"
```

Footer setup
```
footer:
  - name: "Github"
    url: "https://github.com/mesinkasir/cax"
  - name: "Download"
    url: "https://creativitaz.gumroad.com/l/cax"
  - name: "Hire"
    url: "https://www.fiverr.com/creativitas/design-your-modern-website-using-jekyll"
```

Hero home page setup
```
hero:
  badge: "✦ CAX SSG V1.0"
  title: "Static Site Generator\nBuilt in Pure C"
  subtitle: "Blazing fast, zero dependencies,\nand no runtime overhead."
  description: "CAX SSG processes Markdown with frontmatter, renders templates,\nand generates a complete static website in under 50 milliseconds."
  cta_text: "Get Started"
  cta_url: "/posts/"
```

Complete Setup
```
title: "Static Site Generator Built in Pure C"
description: "Blazing fast zero dependencies,and no runtime overhead."
image: "/img/c.webp"
logo: "/img/c.webp"
url: "/"
author: "AXCORA"
navbar_title: "CAX SSG BLOG"
navbar_list:
  - name: "Home"
    url: "/"
  - name: "Article"
    url: "/posts/"
  - name: "About"
    url: "/about/"
  - name: "Docs"
    url: "https://cax.axcora.com/about/"
  - name: "Download"
    url: "https://creativitaz.gumroad.com/l//cax"
  - name: "Github"
    url: "https://github.com/mesinkasir/cax"
footer:
  - name: "Github"
    url: "https://github.com/mesinkasir/cax"
  - name: "Download"
    url: "https://creativitaz.gumroad.com/l/cax"
  - name: "Hire"
    url: "https://www.fiverr.com/creativitas/design-your-modern-website-using-jekyll"
hero:
  badge: "✦ CAX SSG V1.0"
  title: "Static Site Generator\nBuilt in Pure C"
  subtitle: "Blazing fast, zero dependencies,\nand no runtime overhead."
  description: "CAX SSG processes Markdown with frontmatter, renders templates,\nand generates a complete static website in under 50 milliseconds."
  cta_text: "Get Started"
  cta_url: "/posts/"
```

### Collections

CAX is support with auto collections page, you can easy to create a new folder and name it with `posts`for example.

then create a mew file on `content/posts/md` , and setup your posts collections, format: 
```
---
layout: starter/post.cax
hero: 
  title: Blog - CAX SSG
  info: Editorial
  description: All articles about CAX Static Site Generator
collection: posts
pagination: 6
---
```

### Page

You can udpate or create new static page access on `content` and create your new markdown file , example `about.md`.

format:
```---
title: About CAX
description: Why CAX was created - Blazing fast Static Site Generator in pure C for everyone
layout: starter/info.cax
---

## About CAX

CAX was created for one simple reason: **make static site generation easy, fast, and accessible for everyone.**
```

### Posts

After you have create a collections folder `posts` now you can update or create a new posts , create new markdown file, example `content/posts/deploy.md`

format: 
```
---
title: Deploy CAX SSG to Production
description: Deploy your static site to GitHub Pages, Vercel, Netlify, or any host.
layout: starter/detil.cax
image: /img/minima/cax-opening.webp
tags: ["deployment", "production", "hosting"]
date: 2026-06-20
author: CAX Team
---
CAX SSG generates aritlce here...
```

### Deploy

next you can publish your site on your hosting.
run
```
cax build
```

and upload your `site` folder in to to Netlify, Vercel, Cloudflare Pages, or any static hosting.

### Support

+ [Support via PayPal](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=JVZVXBC4N9DAN)
+ [Support via Github](https://github.com/sponsors/mesinkasir)
+ [Support via Gumroad](https://creativitaz.gumroad.com/coffee)
