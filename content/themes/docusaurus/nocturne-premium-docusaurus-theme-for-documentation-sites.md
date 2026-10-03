---
layout: themes-detil.cax
title: Nocturne - Premium Docusaurus Template - Docs, Blog, Decap CMS, Search
description: Premium Docusaurus documentation template with docs, blog, landing, Decap CMS, Pagefind search, dark mode. Fast, SEO ready, MDX, own 100% source, one-time.
image: react/docusaurus-premium1_pbinv1.jpg
features:
  - React + Docusaurus + TypeScript
  - Documentation + Blog + Landing
  - Decap CMS Integration
  - Pagefind Search
  - Dark Mode + Light Mode
  - MDX + Markdown + JSON
  - Static Pages + Pricing + Services
  - Own 100% Source
download: https://creativitaz.gumroad.com/l/nocturne
demo: https://nocturne.axcora.com/
tags:
    - docusaurus
    - docs template
    - documentation template
    - premium docusaurus
    - decap cms
    - pagefind search
    - docusaurus template
    - react template
    - docusaurusthemes
    - premiumthemes
    - featured
---

## Start with Nocturne

Nocturne is a complete set to build your website, blog, and documentation projects.

Preparation for using Nocturne project — premium [Docusaurus](https://docusaurus.io) theme.

### Node / Yarn Download

First we need third party app for work with Nocturne project. Download this app:

- [Node Js Download →](https://nodejs.org/en/download/current)
- Optional [Download Yarn →](https://classic.yarnpkg.com/lang/en/docs/install/)
- Nocturne Project

After download third party apps, install it on your device. Open terminal / Command Prompt and check your apps, run this command `npm -v` for node, or run `yarn -v` for yarn.

### Download Nocturne

Next step you can [download Nocturne project →](https://creativitaz.gumroad.com/l/nocturne)

---

## Create Project

First we need to create new folder for your project.

### Add new Project Folder

Now you can create project folder. Name it with your project or site. For example we create new project folder on desktop and the folder name is `nocturne`.

### Extract Nocturne

Next we need to extract Nocturne project into your new project folder. Open `nocturne.zip` files and extract on your project folder on `desktop/nocturne`.

---

## Installation Nocturne

How to install Nocturne Docusaurus theme project.

### Access Project

Now you can open terminal and access into your project folder. For example we have create new project folder and call it `nocturne` on desktop, so you can run this command:

`cd C:\Users\pcname\Desktop\nocturne`

Change `pcname` with your device pc name.

### Run Installation

Now we can run installation with this command:

`npm install`

If you use yarn you can run this command:

`yarn install`

---

## Run Nocturne

After installation, now we can run Nocturne project on your device.

### Run Project

Open terminal and run this command: `npm start`

Next you can open `localhost:3000` on your web browser.

---

## Github Setup

After your project has successfully run on your local device, next step we need to create github repo for your documentation site.

### Create Github Account

Visit on github.com and register for create new account, or you can use your github account.

Next step create new repo for your documentation site project.

### Github Repo

Now we can create a new repo for your project.

### Create Repo

Login on github with your account, next you can see on header navbar — click on `+` plus icon and select new repository.

Now you can name your new repo with your project, and you can choose public if you want everyone to be able to contribute to your documentation project, or you can choose private if you want your project to not use documentation contributions.

Click Add Readme.

And push Create Repository button.

### Clone Repo

Now we can clone your github repo into your local device.

But first you need activate personal access token. Click on your github profile → Settings → Developer Settings → and create your Personal Access token.

### Run Clone

Open terminal and redirect to your desktop by run this command: `cd C:\Users\Pcname\Desktop`

Next step you can run `git clone youraccesstoken/yourgithubname/yourrepo.git`

Change `youraccesstoken` with your github access token, change `githubusername` with your github name, and change your repo with your repo project name.

### Move Project folder

Next we can move all your `desktop/projectfolder` into your `desktop/githubrepoclone` folder.

Copy and paste all files.

---

## Folder Structure

- `blog` for write and update your blog post article
- `data` for update your design and content for static page
- `docs` for write and update your documentation article
- `src` to configure your theme site and create static pages inside the pages folder
- `static` for your media storage such as images, etc
- `docusaurus.config.ts` for configure your site

---

## Site Setup

Configuration and setup your documentation website project.

## Config files

To set up your site, you can open the configuration file, open `docusaurus.config.ts` in the root project, and open with a code editor.

### SEO Config

First we need to add site title, favicon, tagline and others. For favicon image you can use local storage on `static` folder or use CDN image.

```typescript
  title: 'Your site name',
  tagline: 'your tagline in here..',
  favicon: 'url for image favicon',
  url: 'insert your domain name here',
  baseUrl: '/',
  organizationName: 'Your github account',
  projectName: 'Your github repo',
```

Implementation:

```typescript
  title: 'Nocturne',
  tagline: 'Documentation that feels premium.',
  favicon: 'img/nocturne-favicon.webp',
  url: 'https://nocturne.axcora.com',
  baseUrl: '/',
  organizationName: 'axcora',
  projectName: 'nocturne',
```

### Navigation

Next you can change and update header navigation menu on this line code.

```typescript
  themeConfig:
    ({
      image: 'Image for twitter card and open graph',
      navbar: {
        title: 'Nav title here..',
        logo: {
          alt: 'Alt logo here..',
          src: 'URL Image for your logo..',
        },
        items: [
          { to: 'url Router for your page here..', label: 'Name your Nav Menu', position: 'left' },
          { to: '/', label: 'Home', position: 'left' },
          {type: 'docSidebar', sidebarId: 'mainSidebar', position: 'left', label: 'Documentation'},
          {href: 'https://github.com/mesinkasir', label: 'Github', position: 'right'},
        ],
      },
```

By default, Docusaurus uses two navigation sections — left and right. So you can customize the navigation bar menu based on its position. For example left is for left navbar, and right for right navbar.

Implementation for left navbar use `position:'left'`. If you want to use nav menu on right side so you can use this `position:'right'`.

Next you need to know about the use of links or routers. If you want to be linked to your local page for example on a static page or a dynamic page such as a blog or document article so you can use `to`. If you want to create an outbound link, so you can use `href`.

Implementation on your local router page: `to: '/about'`

Implementation on your outbound link: `href: 'https://github.com/mesinkasir'`

Implementation complete code look like this:

```typescript
  themeConfig:
    ({
      image: 'img/nocturne-og.webp',
      navbar: {
        title: 'NOCTURNE',
        logo: {
          alt: 'Premium Docusaurus Documentation System',
          src: 'img/nocturne-logo.webp',
        },
        items: [
          { to: '/', label: 'Home', position: 'left' },
          { to: '/about', label: 'About', position: 'left' },
          {type: 'docSidebar', sidebarId: 'mainSidebar', position: 'left', label: 'Documentation'},
          { to: '/blog', label: 'Blog', position: 'left' },
          { to: '/pricing', label: 'Pricing', position: 'left' },
          { to: '/contact', label: 'Contact', position: 'left' },
          {href: 'https://github.com/mesinkasir', label: 'Github', position: 'right'},
        ],
      },
```

### Footer Menu

Now we can scroll on footer menu to setup your footer design UI.

```typescript
    footer: {
        style: 'dark',
        links: [
          {
            title: 'Menu 1 Title here..',
            items: [
              {
                label: 'Title menu 1.1 here..',
                to: 'Router link for menu 1',
              },
              {
                label: 'Title menu 1.2 here..',
                to: 'Router link for menu 2',
              },
            ],
          },
        ],
        copyright: `Copyrights Footer area in here..`,
      },
```

Example Implementation:

```typescript
    footer: {
        style: 'dark',
        links: [
          {
            title: 'Docs',
            items: [
              {
                label: 'Getting Started',
                to: '/docs/getting-started/',
              },
              {
                label: 'Configuration',
                to: '/docs/configuration/',
              },
            ],
          },
          {
            title: 'Community',
            items: [
              {
                label: 'GitHub',
                href: 'https://github.com/mesinkasir',
              },
              {
                label: 'Twitter',
                href: 'https://twitter.com/axcoratech',
              },
            ],
          },
          {
            title: 'More',
            items: [
              {
                label: 'Blog',
                to: '/blog',
              },
              {
                label: 'Hire Developer',
                href: 'https://fiverr.com/creativitas',
              },
            ],
          },
        ],
        copyright: `Copyright © ${new Date().getFullYear()} NOCTURNE. Built with Docusaurus.`,
      },
```

You can change it again later after you update and add docs pages, blog pages, and static pages on your site.

---

## Static Page

Nocturne static page features Docusaurus website themes.

---

## Home Page

Update home page design UI and content article page.

### Home Page Data

Now you can change and update home page design UI or update article content. Access on `src/data/home.json` and open with code editor.

### SEO home page

First you can set up SEO for your home page by updating the title and description for your home page.

```json
  "meta": {
    "title": "Nocturne — Premium Docusaurus Documentation System",
    "description": "Elegant documentation. Decap CMS, Pagefind search, and a design that feels premium."
  },
```

### Hero Area

To update your hero area, you can access this line of code, and edit to your needs there.

Example:

```json
  "hero": {
    "badge": "NEW — NOCTURNE v1.0",
    "title": "Documentation<br />that feels<br /><i>premium.</i>",
    "sub": "Nocturne is a Docusaurus documentation system for teams who ship.",
    "actions": [],
    "trust": {},
    "images": {}
  },
```

Implementation:

```json
  "hero": {
    "badge": "NEW — NOCTURNE v1.0",
    "title": "Documentation<br />that feels<br /><i>premium.</i>",
    "sub": "Nocturne is a Docusaurus documentation system for teams who ship. Elegant design, Decap CMS, Pagefind search — all wired.",
    "actions": [
      { "text": "GET NOCTURNE — $145 →", "href": "https://creativitaz.gumroad.com/l/nocturne", "className": "atelier-pill" },
      { "text": "READ THE DOCS", "to": "/docs/intro", "className": "home-btn-ghost" }
    ]
  },
```

### Awards Area

```json
  "awards": [
    "DOCUSAURUS 3",
    "DECAP CMS",
    "PAGEFIND SEARCH",
    "DARK MODE",
    "OWN FOREVER"
  ],
```

### Video Area

```json
  "video": {
    "badge": "LIVE DEMO • NOCTURNE",
    "title": "See Nocturne<br />in action.",
    "sub": "Watch how Nocturne makes documentation feel premium.",
    "iframe": {
      "src": "https://www.youtube-nocookie.com/embed/VIDEO_ID?rel=0&modestbranding=1",
      "title": "Nocturne — Premium Docusaurus Documentation",
      "width": 900,
      "height": 506
    },
    "bar": {
      "left": "● YOUTUBE NOCOOKIE • LAZY",
      "right": "▲ 90++ LIGHTHOUSE • 0 CLS"
    }
  },
```

### Features Area

```json
  "features": {
    "badge": "WHY NOCTURNE",
    "title": "Elegant design.<br />Zero compromise.",
    "cards": [
      {
        "type": "large",
        "title": "Premium Docusaurus Design",
        "text": "Nocturne ships with a complete documentation design system.",
        "image": "/img/mockup/nocturne-feature.webp"
      },
      {
        "type": "small",
        "title": "◍ Decap CMS",
        "text": "Edit every page without code."
      },
      {
        "type": "small",
        "title": "⬙ Pagefind Search",
        "text": "Instant search across all docs."
      }
    ]
  },
```

### Testimonials Area

```json
  "testimonials": {
    "badge": "TRUSTED BY THE AXCORA LAB",
    "title": "Built by a lab that<br />delivers real work.",
    "list": [
      {
        "name": "Axcora Technology",
        "role": "Est. 2018 — Sovereign Web Architect",
        "img": "https://avatars.githubusercontent.com/u/120108849?s=60&v=4",
        "text": "We build documentation systems in 8 languages."
      }
    ]
  },
```

### Pricing Area

```json
  "pricing": {
    "badge": "● PRICING",
    "title": "One payment.<br />Own forever.",
    "sub": "No subscription. No license key. No renewal.",
    "plans": [
      {
        "name": "NOCTURNE",
        "audience": "For studio",
        "badge": "MOST POPULAR",
        "price": "$145",
        "featured": true,
        "items": [
          "✓ Premium Docusaurus design system",
          "✓ Decap CMS pre-configured",
          "✓ Pagefind search integration",
          "✓ Full documentation sections",
          "✓ White-label, resale allowed",
          "✓ Free updates — no renewal ever"
        ],
        "action": {
          "text": "Get Nocturne →",
          "href": "https://creativitaz.gumroad.com/l/nocturne",
          "className": "atelier-pill full"
        }
      }
    ]
  },
```

### Blog Teaser Area

```json
  "blogTeaser": {
    "title": "Read the latest<br />from our journal.",
    "text": "Tutorials, comparisons, and behind-the-scenes from the Axcora lab behind Nocturne.",
    "link": {
      "text": "READ JOURNAL →",
      "to": "/blog"
    }
  },
```

### CTA Area

```json
  "cta": {
    "title": "Build documentation<br />that lasts <i>forever</i>.",
    "action": {
      "text": "GET NOCTURNE — $145 →",
      "href": "https://creativitaz.gumroad.com/l/nocturne",
      "className": "atelier-pill large"
    },
    "sub": "One payment • Own forever • Unlimited projects"
  }
```

---

## About Page

Update about page design UI and content article page.

### About Page Data

Now you can change and update about page design UI or update article content. Access on `src/pages/about.md` and open with code editor.

### SEO for About Page

First, you need to set up your SEO, so you can update your title, description, and cover image here.

Example code:

```markdown
  ---
  title: "About Nocturne — Premium Docusaurus Documentation System"
  description: "Nocturne is a premium Docusaurus documentation system by Axcora Technology."
  keywords:
    - About Nocturne
    - Premium Docusaurus
    - Docusaurus documentation system
  ---
```

---

## Pricing Page

Update pricing page design UI and content article page.

### Pricing Page Data

Now you can change and update pricing page design UI or update article content. Access on `src/pages/pricing.md` and open with code editor.

### Pricing Page Structure

```markdown
  ---
  title: Pricing — Nocturne
  description: One payment. Own forever.
  ---

  # Pricing

  One payment. Own forever. No subscription, no license key, no renewal.

  ## NOCTURNE — $145

  For teams who ship documentation, not demos.

  - ✓ Premium Nocturne design system
  - ✓ Decap CMS pre-configured
  - ✓ Pagefind search integration
  - ✓ Full documentation sections
  - ✓ White-label, resale allowed
  - ✓ Free updates — no renewal ever

  [Get Nocturne →](https://creativitaz.gumroad.com/l/nocturne)
```

---

## Services Page

Update services page design UI and content article page.

### Services Page Data

Now you can change and update services page design UI or update article content. Access on `src/pages/services.md` and open with code editor.

### Services List

```markdown
  ## What We Build

  - Custom Documentation Sites
  - JAMstack Architecture
  - Headless CMS Integration
  - Python Static Site Generators
  - Custom Web Applications

  ## Commission via Fiverr

  [Hire Axcora on Fiverr →](https://www.fiverr.com/creativitas/create-your-custom-website-and-app)
```

---

## Markdown Page

You can create new page by add new markdown files.

### Folder location

For create new article markdown static page you can open on `src/pages`.

### Create markdown article

Next you can create new markdown file, name it with your page, for example `whychoseus.md`.

Add this frontmatter concept:

```markdown
  ---
  title: Hey Markdown Page in here
  description: This description about your markdown files..
  image: img/docusaurus.png
  ---

  write your markdown article in here...
```

### Update markdown article

If you want to edit a Markdown static page, you can open in `src/pages` and select your article, then open with your code editor and edit it.

### Delete markdown article

For delete markdown article page, you can simply just delete `.md` files.

---

## Documentation Page

Documentation page Nocturne dynamic page features Docusaurus website themes.

### New Group Docs

How to create new group categories for your documentation page.

#### Create new Group Docs

First you can access the `docs` folder, create a new folder and rename it to your documentation category — for example `tutorials`.

#### Setup Group Docs

Open `tutorials` folder and create new json files, name it with `_category_.json`.

Now open on `_category_.json` with code editor and insert this code:

```json
  {
    "label": "Your doc title here...",
    "position": 5,
    "collapsed": false,
    "link": {
      "type": "generated-index",
      "title": "Tutorials",
      "description": "Write description about your docs group categories here..."
    }
  }
```

Implementation:

```json
  {
    "label": "Tutorials",
    "position": 5,
    "collapsed": false,
    "link": {
      "type": "generated-index",
      "title": "Tutorials",
      "description": "Step-by-step tutorials for Nocturne."
    }
  }
```

Next if you want to add a new group or document category, you can follow the same steps — don't forget to set up categories position.

Category positions will be displayed on the sidebar documentation page.

### New Article Docs

Create new article documentation page.

#### Create New Docs Article

For create new article docs, you can access on `docs/yourgroupdocfolder` for example you have group categories docs `tutorials`, so you can open `docs/tutorials` folder.

Now you can create new markdown files and name it with your url link for documentation article — for example `how-to-install.md`.

## Docs Frontmatter

Next, you can add this frontmatter on `how-to-install.md` files.

Code:

```markdown
  ---
  title: Your Article title docs here...
  description: Your description about article docs here...
  image: insert url link image for article docs page cover...
  sidebar_position: Insert position number for your article on sidebar here...
  sidebar_label: Short name
  ---

  Write your article docs with markdown here....
```

Implementation:

```markdown
  ---
  title: Installation
  description: How to install Nocturne Docusaurus theme project
  image: img/docusaurus.png
  sidebar_position: 3
  sidebar_label: Installation
  ---

  # Installation Nocturne

  ## Access Project

  Open terminal and access to your project folder.

  `cd C:\Users\pcname\Desktop\nocturne`

  ## Run Installation

  `npm install`
```

### Update Article Docs

How to update, edit, and delete documentation article page.

#### Edit Article Docs

To edit or update a documentation article, you need to open the group documentation folder, then open with the code editor where your article needs to be edited.

#### Delete Article Docs

To delete a documentation article, you need to open the group documentation folder, then select where your article needs to be delete, and delete article.md files.

---

## Blog Page

Blog article page Nocturne dynamic page features Docusaurus website themes.

### Setup Blogs

Setup your blog article page.

#### Add Authors

First, you can set up your author blog posts, open it in `blog/authors.yml` with a code editor, and you can add your authors here.

YAML Code:

```yaml
authorname:
  name: Your Author Name here...
  title: Your author title here....
  url: URL web or social media author profile here...
  image_url: URL or CDN image author here....
```

Implementation:

```yaml
axcora:
  name: Axcora Technology
  title: Sovereign Web Architect & AI Research Lab
  url: https://axcora.com
  image_url: https://avatars.githubusercontent.com/u/120108849?s=120&v=4
  page: true
  socials:
    github: mesinkasir
    newsletter: https://pycora.axcora.com
```

#### Add New Authors

To add a new author you can follow the front matter example.

Example:

```yaml
newauthorname:
  name: Your New Author Name here...
  title: Your New author title here....
  url: URL web or social media new author profile here...
  image_url: URL or CDN image for new author here....
```

### Setup Tags

Open `blog/tags.yml` and add your tags:

```yaml
docusaurus:
  label: Docusaurus
  permalink: /docusaurus
  description: Docusaurus documentation system tutorials and guides.
```

### How to Add New Post

How to create new article for your blog page.

#### New Article

For create new article you can open on `blog` folder, and create new markdown file, name it markdown file with this format `year-month-date-your-url-link` for example `2026-10-25-myfirstpost.md` then open with code editor and write markdown for your new article post.

#### Blog Frontmatter

Slug is for your url, title is for blog title, authors is for your author — you can add new author on `authors.yml`, tags is for your tags.

Example:

```markdown
  ---
  slug: url-link-blog
  title: Your Blog title
  description: Your blog description
  authors:
    - axcora
  tags:
    - docusaurus
    - tutorial
  image: /img/blog/your-post.webp
  date: 2026-10-25
  ---

  Write markdown post here...
```

Implementation:

```markdown
  ---
  slug: first-blog-post
  title: First Blog Post
  authors:
    - axcora
  tags:
    - docusaurus
  image: /img/blog/first-post.webp
  date: 2026-10-25
  ---

  Write markdown post here...

  {/* truncate */}

  ## Full content starts here
```

**Important:** Use `{/* truncate */}` — not `<!-- truncate -->` — because MDX doesn't support HTML comments.

### Update Article Blog

How to update, edit, and delete blog article page.

#### Edit Article Blog

To edit or update a blog article, you need to open the blog folder, then open with the code editor where your article needs to be edited.

#### Delete Article Blog

To delete a blog article, you need to open the blog folder, then select where your article needs to be delete, and delete article.md files.

---

## Update Config

Update Configuration and setup your documentation website project.

### Update Config files

After we have create all static page, add article for documentation, add article for blog page, now we need to update set up your site, you can open the configuration file, open `docusaurus.config.ts` in the root project, and open with a code editor.

And update navigation, footer menus and more according to your needs.

---

## Github Push

Push your final project to the github repo.

### Push Project

Now open terminal and access your clone git project from your github repo before.

Next you can run push github command.

Example:

```yaml
git add .
git commit -m "first commit for my docusaurus website"
git push https://yourtoken@github.com/username/yourrepo.git
```

Change `username` with your github username, and change `your-repo-name` with your github repo, and change `yourtoken` with your github token.

---

## Hosting Deploy

Run and publish make your website live on modern hosting.

For deploy and make your website live, so you need to register on modern static host provider, for example, Cloudflare, Netlify, or Vercel.

Register with your github account.

Next you can click create new project app for Netlify and Vercel or Pages for Cloudflare.

And you can click select and integration with your github repo project.

After you have integration with your github account, now you can select your github repo.

Next you can click deploy, and select Docusaurus as framework.

Click Deploy.

Congratulations your website is live now!

---

## Headless CMS

Work with modern content management system for your Docusaurus project.

If you want to work with CMS, so you can use headless git cms for best solutions.

Same like other cms, with headless cms we can update website and blog quickly.

Include with credential security for login on backend admin, make your website secure.

We can use Decap CMS for cloud cms or use Tina CMS for your local dev mode.

With CMS integration, it makes it easier for you to update quickly without needing coding.

### Decap CMS Setup

Nocturne ships with Decap CMS pre-configured. To use it:

**Terminal 1:**

`npx decap-server`

**Terminal 2:**

`npm start`

Open `http://localhost:3000/admin/` and click Login.

### What You Can Edit

- Site Settings — site config, navbar, widgets, homepage
- Static Pages — `src/pages/*.md`
- Documentation — `docs/*`
- Docs Categories — `_category_.json`
- Blog Posts — `blog/*`

### Limits

Decap CMS cannot:

- Create new folders in `docs/`
- Create `_category_.json` files
- Edit `docusaurus.config.ts`
- Edit `sidebars.ts`

These must be done manually in code.

---

## Need Help?

- Full documentation: https://nocturne.axcora.com/
- Custom build: https://www.fiverr.com/creativitas/create-your-custom-website-and-app
- Get Nocturne: https://creativitaz.gumroad.com/l/nocturne
