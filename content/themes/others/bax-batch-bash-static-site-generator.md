---
layout: themes-detil.cax
title: BAX BATCH BASH Magic Static Site
description: New and Modern static site generator built with Batch. Zero dependencies, cross-platform, and SEO-friendly.
image: others/BAX-SSG_axgl55.jpg
features:
 - Axcora
 - Axcora Zetta Core
 - Starter Project
 - Fast Website
 - Auto SEO
 - Fast Build
 - Zet Data
 - Zet Content
 - Batch / BASH SSG
 - All Static Hosting support Vercel, Cloudflare, Netlify , Github Pages and others.
 - All PHP Hosting support Cpanel, Plesk, Direct Admin , VPS and others.
download: https://creativitaz.gumroad.com/l/bax
demo: https://bax.axcora.com/
tags:
  - themestemplate
  - website themes
  - website template
  - blog template
  - themes
  - template
  - freethemes
  - batchthemes
  - bashthemes
  - otherthemes
  - others
date: 2026-08-07
---
### Introduction

BAX is a modern, lightweight, and SEO-friendly static site generator built with pure Batch (Windows) and Bash (Linux/Mac) scripts. No dependencies, no npm, no Python - just pure shell scripts that generate static HTML pages from simple .zet files.

### Features

BAX SEO Features Auto-Generated Meta Tags, BAX automatically generates SEO-friendly meta tags:
+ Title tag
+ Description meta
+ Op+en Graph tags (Facebook, LinkedIn)
+ Twitter Card tags (Twitter)
+ Generator meta
+ Sitemap & Robots

BAX automatically generates:
+ sitemap.xml - for search engines
+ robots.txt - for crawler instructions

BAX uses a priority system for SEO metadata:
+ Post/Page specific (highest priority)
+ Site-wide config (fallback)
+ Default values (last resort)

### Installation

Open terminal and run this command
```
git clone https://github.com/mesinkasir/bax.git
cd bax
```

### Buidl the project

Windows OS Build Command
```
bax.bat
```

Linux / MacOs build command
```
./bax.sh
```

### Run the project

Run project on Windows OS
```
run.bat
```

Run on Linux or MacOS
```
./run.sh
```

This will start a local server at `http://127.0.0.1:3000`

### Project Structure

```
bax/
├── bax.bat            # Windows build script
├── bax.sh             # Linux/Mac build script
├── run.bat            # Windows dev mode script
├── run.sh             # Linux/Mac dev mode script
├── config.zet         # Site configuration
├── style.css          # Custom styles
├── data/              # Blog posts
│   └── *.zet
├── pages/             # Static pages
│   └── *.zet
└── public/            # Generated output (auto-created)
    ├── index.html
    ├── pages/
    ├── tags/
    └── *.html
```

### Site Configuration

Open on config.zet then update with or site
```
SITE_TITLE:BAX SSG
SITE_URL:http://127.0.0.1:3000
SITE_DESCRIPTION:Modern static site generator built with Batch
SITE_IMAGE:https://axcora.com/default-og.jpg
SITE_FAVICON:/favicon.ico
POSTS_PER_PAGE:6

NAV:
  - text: Home
    url: /
  - text: About
    url: /pages/about.html
  - text: Portfolio
    url: /pages/portfolio.html
  - text: Contact
    url: /pages/contact.html
```

SITE - is for your default SEO metadata tag, open graph, and twitter card.

NAV to update your navbar list.

### .Zet Schema

Simple content with zet schemes.
```
H1: Heading 1
H2: Heading 2
H3: Heading 3
H4: Heading 4
H5: Heading 5
H6: Heading 6
P: Paragraph
UL: ul list
LI: i list
CODE: Code tags
```

### Static Page

To update and create static page you can access on `pages` folder, then create your new static page, example `about.zet`

implementation
```
TITLE:About BAX - Modern Static Site Generator
DESC:Learn about BAX, a lightweight and SEO-friendly static site generator built with Batch and Bash.
IMG:https://placehold.co/800x400/0f172a/ffffff?text=About+BAX

H1:About BAX

H2:What is BAX?
P:BAX is a modern, lightweight, and SEO-friendly static site generator built with pure Batch (Windows) and Bash (Linux/Mac) scripts. No dependencies, no bloat - just pure static site magic!

P:BAX stands for Batch and Axcora X, combining the power of Windows Batch and Linux Bash with Axcora Tech's commitment to simplicity and performance.

H2:Why BAX?
P:BAX was created to make static site generation simple and accessible for everyone. You don't need to learn complex frameworks or install massive dependencies.

H3:Key Principles
UL:
LI:Simplicity - Just write content in .zet format and build
LI:Performance - Builds your entire site in milliseconds
LI:Portability - Runs on Windows, Linux, and macOS
LI:SEO - Built-in optimization with meta tags, Open Graph, and sitemaps
LI:Zero Dependencies - Uses only built-in shell commands
/UL:

H2:Inspiration
P:BAX is inspired by the simplicity of Hugo and Jekyll, but built for people who want even simpler tools. It's perfect for personal blogs, documentation sites, portfolio websites, and small business landing pages.

H2:Who is BAX For?
UL:
LI:Developers who want a simple static site generator
LI:Bloggers who want SEO-friendly content
LI:Non-developers who want an easy way to build websites
LI:Anyone who wants to understand how static sites work
/UL:

H2:Features
UL:
LI:Zero dependencies
LI:Cross-platform (Windows, Linux, macOS)
LI:SEO optimized (meta tags, Open Graph, Twitter Cards)
LI:Simple .zet format
LI:Tag support with auto-generated tag pages
LI:Pagination for blog posts
LI:Customizable design with CSS
LI:Sitemap and robots.txt generation
LI:Bootstrap 5 for responsive design
/UL:

H2:Get Started Today
P:Clone the repository and start building your static site in minutes!

CODE:git clone https://github.com/mesinkasir/bax.git
CODE:cd bax
CODE:bax.bat  # Windows
CODE:./bax.sh # Linux/Mac

H2:Version
P:BAX v1.0 - Released July 2026

H2:License
P:BAX is open-source under the MIT License.

TAGS:about bax ssg static-site
```

SEO page
```
TITLE:About BAX - Modern Static Site Generator
DESC:Learn about BAX, a lightweight and SEO-friendly static site generator built with Batch and Bash.
IMG:https://placehold.co/800x400/0f172a/ffffff?text=About+BAX
```

After you have input seo configuration for your page you can simply write your content.

### Blog Post

to update blog post you can access on `data` folder and create your new post example `compare.zet`

.zet implementation format
```
TITLE:BAX vs Hugo, Jekyll, and 11ty - Which One to Choose?
DATE:13 July 2026
IMG:https://placehold.co/800x400/0f172a/ffffff?text=BAX+vs+Others
DESC:Compare BAX with Hugo, Jekyll, and 11ty. Find out which static site generator is right for you.
TAGS:bax hugo jekyll 11ty comparison

H2:Why BAX is Different
P:BAX is not trying to replace Hugo, Jekyll, or 11ty. It's a different tool for different use cases. BAX focuses on simplicity, zero dependencies, and ease of use.

H2:Quick Comparison
H3:BAX vs Hugo
UL:
LI:BAX: Zero dependencies, very easy to learn, builds in milliseconds
LI:Hugo: Requires Go, steep learning curve, faster but complex
/UL:

H3:BAX vs Jekyll
UL:
LI:BAX: Runs on any platform, simple .zet format, lightweight
LI:Jekyll: Requires Ruby, uses Markdown, heavier and slower
/UL:

H3:BAX vs 11ty
UL:
LI:BAX: No dependencies, ultra-simple, fast builds
LI:11ty: Requires Node.js, flexible but more complex setup
/UL:

H2:Choose BAX If:
UL:
LI:You hate installing dependencies
LI:You want a simple blog or personal site
LI:You work across different operating systems
LI:You appreciate minimalist tools
/UL:

P:Check out <a href="https://bax.axcora.com">BAX Magic SSG</a> for more information.

TAGS:bax hugo jekyll comparison
```

### Deploy Production

After you have finsih update yoru site, now you project is ready to deploy for production.

run build command :

windows
```
bax.bat
```

Linux / macOS
```
./bax.sh
```

And upload your `public` folder in to your hosting.

#### GitHub Pages
BAX includes a ready-to-use GitHub Actions workflow.
Rename workflow file
```
mv .github/workflows/deploy.yml.example .github/workflows/deploy.yml
```
Push to GitHub
```
git add .
git commit -m "Deploy BAX site"
git push origin main
```

Then enable GitHub Pages in your repository settings.

#### Netlify

Netlify action:
+ Build command: ./bax.sh
+ Publish directory: public/

#### Vercel

Vercel setup: 
+ Build command: ./bax.sh
+ Output directory: public/

#### Cloudflare

Cloudflare Pages Setup
+ Build command: ./bax.sh
+ Build output: public/


### Support BAX Project

+ [Support via PayPal](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=JVZVXBC4N9DAN)
+ [Support via Github](https://github.com/sponsors/mesinkasir)
+ [Support via Gumroad](https://creativitaz.gumroad.com/coffee)
