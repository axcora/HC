---
layout: themes-detil.cax
title: Minimal lua Themes LUAX SSG
description: Free download and open source code lua Minimalis clean project website blog themes template.
image: lua/lua-ssg_ospy5i.jpg
features:
 - LUA
 - Lua Tech
 - LUA SSG
 - LUAX Template
 - Auto SEO
 - Auto Collections
 - YAML / JSON Data
 - Markdown Content
 - Axcora Zetaa Core Engine
 - Modern Host support netlify vercel cloudflare Github Pages and others 
 - Build production host firebase surge cpanel vps direct admin plesk and others
download: https://creativitaz.gumroad.com/l/luax
demo: https://luax.axcora.com/
tags:
  - themestemplate
  - website themes
  - website template
  - luatemplate
  - luassg
  - themes
  - blog template
  - template
  - luathemes
  - jamstackthemes
  - freethemes
date: 2026-08-07
---

### Introduction

A starter project for LUAX LUA SSG

LUAX is a static site generator built with [Lua](https://www.lua.org/). It was created to make building static websites simple, fast, and fun.

Lua is lightweight, fast, and easy to learn. It's often used in game development and embedded systems, but it's also perfect for building CLI tools and web generators.

### Features

LUAX LUA SSG STATIC SITE GENERATOR MAGIC FEATURES: 

📝 Markdown content with YAML frontmatter
🏷️ Automatic tag pages
📄 Pagination for blog posts
🎨 Custom layouts with LAX template engine
🔍 SEO with Open Graph, JSON-LD, and sitemap
📡 RSS feed for your blog
🖼️ Asset management with public folder
🚀 Blazing fast builds

### Philosophy

The LUAX LUA Static Site Generator SSG Philosophy: 
+ Simple — No unnecessary complexity
+ Transparent — You control everything
+ Performant — Build time should not waste your time
+ Portable — Works on any platform

### Get Start

For first you need to download lua : https://www.lua.org/download.html

Next open terminal and clone this project
```
git clone https://github.com/yourusername/luax.git
cd luax
```

#### Windows

Build your project
```
luax build
```

Run your project
```
luax start
```

Access on `http://localhost:8080`

#### Linux MacOs

Prepare
```
chmod +x luax.sh
```

Build your project
```
./luax.sh build 
```

Run your project
```
./luax.sh start
```

Access on `http://localhost:8080`

### Architecture

The LUAX Architecture
```
luax/
├── build.lua          # Build engine
├── start.lua          # Development server
├── lax.lua            # LAX template engine
├── yaml.lua           # YAML parser
├── metadata.yaml      # Site configuration
├── luax.bat           # Windows command line
├── luax.sh            # Linux/Mac command line
├── src/
│   ├── posts/         # Blog posts (.md)
│   └── pages/         # Static pages (.md)
├── templates/
│   ├── layouts/       # Layout templates (.lax)
│   └── partials/      # Partial templates (.lax)
├── public/            # Static assets (css, img, js)
├── dist/              # Generated output
```

### Setup

For first you can configuration your SEO website access on `data/metadata.yaml`

format
```
title: LUAX SSG
description: Static Site Generator built with Lua
url: http://localhost:8080
image: /img/logo.webp
favicon: /img/favicon.webp
```

### Media

You can upload your static folder in `public` such css , image, video , file and others.

### Content

#### Static Page

To update static page you can access on `src/pages` then create a new markdown file , example `about.md`

format:
```
---
title: About LUAX
description: LUAX is a simple static site generator built with Lua. Learn about the project, why we built it, and how it works.
layout: page.lax
image: /img/darkluax2.webp
---
## About LUAX SSG

LUAX is a **static site generator built with Lua**. It was created to make building static websites simple, fast, and fun.
```

#### Posts Article

To update your blog post article you can simply access on `src/posts` , and create your new markdown file, example `deploy.md`.

Format:
```
---
layout: post.lax
title: Deploying LUAX Sites
date: 2026-07-15
image: /img/neonluax.webp
author: Axcora
tags: deployment, github-pages, netlify
excerpt: Learn how to deploy your LUAX site to production.
---
# Deploying LUAX Sites

Deploy your LUAX site to any hosting platform.
```

### Deploy

Next you can build production with run this command
```
luax build
```

and upload your `dist` folder in to your hosting.

Github pages is ready with `deploy.yml` just rename deploy.yml.example to be deploy.yml - Next activate your github pages.

### Support

+ [Support via PayPal](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=JVZVXBC4N9DAN)
+ [Support via Github](https://github.com/sponsors/mesinkasir)
+ [Support via Gumroad](https://creativitaz.gumroad.com/coffee)
